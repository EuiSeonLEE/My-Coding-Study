#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>      //time()
#include<Windows.h>

#pragma warning(disable : 4996)
#pragma warning(disable : 4244)
#define hid_layer 8
#define bias_toggle 1
#define l_gain 0.8
#define Epochs 100000

double w[10][2]; // input layer - hidden layer w
double w_out[10]; // hidden layer - output layer w
double w_bias[11]; //bias
double u[11] = {0.0, }; //output U
double Delta[11] = {0.0, }; // delta
double E = 0; //error
double TH = 0.5;
short Bool = 1;

void Error_back(double x1, double x2, double t){
    if(Bool){
        srand(time(NULL));
        for(int a = 0; a < hid_layer; a++){
            for(int b = 0; b < 2; b++){
                w[a][b] = (double)(((rand() % 31) - 15.0) / 10.0);
            }
            w_out[a] = (double)(((rand() % 31) - 15.0) / 10.0);
            if(bias_toggle) w_bias[a] = (double)(((rand() % 31) - 15.0) / 10.0);
        }
    Bool = 0;
    }
    for(int a = 0; a < hid_layer; a++){
        u[a] = x1 * w[a][0] + x2 * w[a][1]; //S[a]를 따로 두지 않고 u[a]에 직접적으로 계산 유도
        if(bias_toggle) u[a] += w_bias[a];
        u[a] = 1 / (1 + exp(-u[a])); //sigmod
        
        u[hid_layer] += u[a] * w_out[a];
    }
    if(bias_toggle) u[hid_layer] += w_bias[hid_layer];

    u[hid_layer] = 1 / (1 + exp(-u[hid_layer])); //sigmod

    E += (((t - u[hid_layer]) * (t - u[hid_layer]))/2);
    
    Delta[hid_layer] = u[hid_layer] * (1 - u[hid_layer]) * (t - u[hid_layer]);

    for(int a = 0; a < hid_layer; a++){
        Delta[a] = u[a] * (1 - u[a]) * w_out[a] * Delta[hid_layer];
    }
    for (int a = 0; a < hid_layer; a++) {
      w_out[a] += Delta[hid_layer] * u[a] * l_gain;
      w[a][0] += Delta[a] * x1 * l_gain;
      w[a][1] += Delta[a] * x2 * l_gain;
      if(bias_toggle) w_bias[a] += Delta[a] * l_gain;
   }
}

int Grid(double x1, double x2)
{
   double s = 0, s_out = 0, u_tmp[11] = {0.0,};
   for (int a = 0; a < hid_layer; a++) {
      u_tmp[a] = x1 * w[a][0] + x2 * w[a][1];
      if (bias_toggle) u_tmp[a] += w_bias[a];

      u_tmp[a] = 1 / (1 + exp(-u_tmp[a]));

      u_tmp[hid_layer] += u_tmp[a] * w_out[a];
   }
   
   if (bias_toggle) u_tmp[hid_layer] += w_bias[hid_layer];

   u_tmp[hid_layer] = 1 / (1 + exp(-u_tmp[hid_layer]));

   if (u_tmp[hid_layer] >= TH)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

int main()
{
    FILE* fd; // input_data.txt 파일
    FILE* err; // error_data.txt 파일
    FILE* grd0; // grid0_data.txt
	FILE* grd1; // grid1_data.txt
   if ((fd = fopen("input_data.txt", "r")) == NULL) 
   {
      printf("can't find file \n");
      exit(1);
   }
   if ((err = fopen("errordata.txt", "w")) == NULL) 
   {
      printf("can't find file \n"); 
      exit(1);
   }
   if ((grd0 = fopen("grid0_data.txt", "w")) == NULL)
   {
      printf("can't find file \n");
      exit(1);
   }
   if ((grd1 = fopen("grid1_data.txt", "w")) == NULL) 
   {
      printf("can't find file \n"); 
      exit(1);
   }


   
   
   double x1, x2, t = 0;
   
   for (int i = 0; i < Epochs; i++)
   {
      rewind(fd);//파일 포인터 위치 초기화
      E = 0;
      while (fscanf(fd, "%lf %lf %lf\n", &x1, &x2, &t) != EOF) {
         Error_back(x1, x2, t);
      }
      fprintf(err, "%lf\n", E);
      printf("%dth : epochs-", i + 1);
      printf("Error = %lf\n", E);
   }

   int error = 0;

   for (double x2 = 3; x2 >= -3; x2 -= 0.1) {
      for (double x1 = -3; x1 <= 3; x1 += 0.1) {
         int tmp_t = Grid(x1, x2);

         if(tmp_t == 1) fprintf(grd1, "%lf %lf \n", x1, x2);
         if(tmp_t == 0) fprintf(grd0, "%lf %lf \n", x1, x2);
         
      }
   }

   fclose(fd);
   fclose(err);
   fclose(grd0);
   fclose(grd1);
}