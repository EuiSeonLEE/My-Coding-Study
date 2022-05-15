#include <stdio.h>
#include <math.h>
#pragma warning(disable : 4996)
#pragma warning(disable : 4244)
#define Neurons 4
#define bias 0
#define ETA 0.8

double w[2][10] = { {-0.3, -0.2, -0.1, 0.5, 0.6, 0.7, 1, 1.2, 1.5, 1.7},
               {-0.5, -0.4, -0.3, 0.1, 0.4, 0.8, 1.1, 1.3 , 1.4, 1.6} }; // input layer - hidden layer w
double w_out[10] = { -0.8, -0.7, -0.5, -0.3, 0.2, 0.4, 0.5, 0.7, 0.8, 1 }; // hidden layer - output layer w
double w_bias[11] = { -1, -0.8, -0.5, -0.3, 1, 0.5, 0.6, 0.8, 1.3, 1.5, 1.6 }; //bias
double u[11] = { 0,0,0,0,0,0,0,0,0,0,0 }; //output U
double Delta[11] = { 0,0,0,0,0,0,0,0,0,0,0 }; // delta
double E = 0; //error

double TH = 0.5;

void Error_back(double x1, double x2, double t)
{
   double s = 0;
   double s_out = 0;


   for (int i = 0; i < Neurons; i++) {
      s = x1 * w[0][i] + x2 * w[1][i];
      if (bias) s += w_bias[i];
      u[i] = 1 / (1 + exp(-s));

      s_out += u[i] * w_out[i];
   }

   if (bias) s_out += w_bias[Neurons];

   u[Neurons] = 1 / (1 + exp(-s_out));

   E += fabs(t - u[Neurons]);

   Delta[Neurons] = u[Neurons] * (1 - u[Neurons]) * (t - u[Neurons]);

   for (int i = Neurons - 1; i >= 0; i--) {
      Delta[i] = u[i] * (1 - u[i]) * Delta[Neurons] * w_out[i];
   }

   for (int i = 0; i < Neurons; i++) {
      w_out[i] += Delta[Neurons] * u[i] * ETA;
      w[0][i] += Delta[i] * x1 * ETA;
      w[1][i] += Delta[i] * x2 * ETA;
      w_bias[i] += Delta[i] * ETA;
   }
}
int Grid(double x1, double x2)
{
   double s = 0, s_out = 0, U_tmp[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
   for (int i = 0; i < Neurons; i++) {
      s = x1 * w[0][i] + x2 * w[1][i];
      if (bias) s += w_bias[i];

      U_tmp[i] = 1 / (1 + exp(-s));
   }
   for (int i = 0; i < Neurons; i++)
   {
      s_out += U_tmp[i] * w_out[i];
   }

   if (bias) s_out += w_bias[Neurons];

   U_tmp[Neurons] = 1 / (1 + exp(-s_out));

   if (U_tmp[Neurons] >= TH)
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
   FILE* fd_in;
   FILE* fd_out;
   FILE* fd_grid0;
   FILE* fd_grid1;

   if ((fd_in = fopen("inputdata.txt", "r")) == NULL)
   {
      printf("can't find file \n"); // 읽지 못하면 에러
      return -1;
   }
   if ((fd_out = fopen("outputdata.txt", "w")) == NULL)
   {
      printf("can't find file \n"); // 읽지 못하면 에러
      return -1;
   }
   if ((fd_grid0 = fopen("gridFile0.txt", "w")) == NULL)
   {
      printf("can't find file \n"); // 읽지 못하면 에러
      return -1;
   }
   if ((fd_grid1 = fopen("gridFile1.txt", "w")) == NULL)
   {
      printf("can't find file \n"); // 읽지 못하면 에러
      return -1;
   }
   double x1, x2, t = 0;
   int epochs = 1;

   for (int i = 0; i < 10000; i++)
   {
      rewind(fd_in);
      E = 0;
      while (fscanf(fd_in, "%lf %lf %lf\n", &x1, &x2, &t) != EOF) {
         Error_back(x1, x2, t);
      }
      fprintf(fd_out, "%lf\n", E);
      printf("%dth : epochs-", epochs);
      printf("Error = %lf\n", E);
      epochs++;
   }

   int error = 0;

   for (double x2 = 3; x2 >= -3; x2 -= 0.1) {
      for (double x1 = -3; x1 <= 3; x1 += 0.1) {
         int tmp_t = Grid(x1, x2);

         if (x2 >= -0.5 && x1 - x2 >= -1 && x1 + x2 <= 2 && tmp_t == 1) {}
         else if (tmp_t == 1) error++;
         else if (x2 >= -0.5 && x1 - x2 >= -1 && x1 + x2 <= 2 && tmp_t == 0) error++;
         if(tmp_t == 1) fprintf(fd_grid1, "%lf %lf \n", x1, x2);
         if(tmp_t == 0) fprintf(fd_grid0, "%lf %lf \n", x1, x2);
         
      }
   }
   printf("%d ddd", error);

   fclose(fd_in);
   fclose(fd_out);
   fclose(fd_grid0);
   fclose(fd_grid1);
}