#include <stdio.h>
#include <stdlib.h>

int n = 1; //epochs의 카운트를 올려주는 변수
double w1 = 0, w2 = 0, TH = 0; // weight값과 threshold값
double y = 0.0; //좌표값과 weight 값의 연산 합을 저장할 변수
int CH; //  CH는 AND연산과 OR연산 과정 자체를 구분할 변수
int x[4][2] = { {0,0}, {0,1}, {1,0}, {1,1} }; // 2차원 배열 선언 각각 x1,x2의 4개의 좌표를 받음
int target[2][4] = { {0,0,0,1}, {0,1,1,1} }; // 순서대로 AND연산일 경우 target의 값과 OR연산일 경우의 target값
double E = 0;
double error = 0;
double gain = 0;

void calculate(){  
   E = 0;   // 사용될 Energy function값 초기화 
   for (int i = 0; i < 4; i++)   //(0,0)~(1,1)까지 4번 연산 
    {
        y = w1 * x[i][0] + w2 * x[i][1];   // y 연산 값
        error = target[CH][i] - y;   // AND 또는 OR연산을 고려한 target값과 y값를 통해 error 계산 
        E += (error * error);
        w1 += gain * error * x[i][0];   //설정했던 learning gain과 error로 wn+1수정한다 
        w2 += gain * error * x[i][1];
    }
}
void AND_OR(){ // AND와 OR연산
    FILE* out; // output_data.txt 파일
    if ((out = fopen("output_data.txt", "w")) == NULL) // 쓰기 모드로 output_data.txt파일을 연다
    {
        printf("can't find file \n"); // 읽지 못하면 에러
        exit(1);
    }
    while (n < 100) //시도 회수가 100회를 넘지 않는 동안
    {
        calculate();
        //fprintf(out, "w1           w2           E\n");
        fprintf(out, "%lf %lf %lf\n", w1, w2, E/2);
        n = n+1; //시도 회수 1회 증가
    }
    fclose(out);
    // 100번의 계산 시도 후 종료
}

int main(){
   printf("w1 값을 입력하시오 : "); // 사용자로부터 w1값을 입력받는다.
   scanf("%lf", &w1);
   printf("w2 값을 입력하시오 : "); // 사용자로부터 w2값을 입력받는다.
   scanf("%lf", &w2);
   printf("Learning Gain값을 입력하시오 : "); // 사용자로부터 Threshold값을 입력받는다.
   scanf("%lf", &gain);
   //과제에는 w1 = 0.5 , w2 = -0.4, gain = 0.05 값 사용
  
   printf("연산 선택(0 = AND, 1 = OR) : "); // 연산을 선택한다 0이면 AND 연산, 1이면 OR연산
   scanf("%d", &CH);

   AND_OR(); // AND 또는 OR연산의 target과 실제 threshold된 y값을 비교한다.

   printf(" fixed w1 : %lf\n fixed w2 : %lf\n Energy : %lf\n", w1, w2 , E/2); // AND_OR()을 거쳐 fix된 w1과 w2를 출력한다.
   printf("end\n");
   
   return 0;
}