#include <stdio.h>
#pragma warning(disable : 4996)
#define MIN 0.0003;

int n = 1; //epochs의 카운트를 올려주는 변수
double w1 = 0, w2 = 0; // weight값
int CH; // AND연산과 OR연산 과정 자체를 구분할 변수
double S; // 실제 연산 결과 값을 저장할 변수
double y;
int x[4][2] = { {0,0}, {0,1}, {1,0}, {1,1} }; // 2차원 배열 선언 각각 x1,x2의 4개의 좌표를 받음
int target[2][4] = { {0,0,0,1}, {0,1,1,1} }; // 순서대로 AND연산일 경우 target의 값과 OR연산일 경우의 target값
double Error = 0; //Error 값
double Emin = MIN; // 루틴 내부에서 최솟값이 나온 경우 E를 근사화 하기 위한 값
double E = 0; // Error 값을 미분하기 위해 선언
double a = 0; // learing gain(learing rate) 0<a<1

void AND_OR() // AND와 OR연산 결정 후 가중치를 Gradient하는 함수
{

   FILE *out; // output_data.txt 파일
   if ((out = fopen("output_data.txt", "w")) == NULL) // 쓰기 모드로 output_data.txt파일을 연다
   {
      printf("can't find file \n"); // 읽지 못하면 에러
      exit(1);
   }

   int check = 0;

   while (check != 4) { //각각 4개의 쌍의 y와 t를 비교하여 한 쌍 비교시 마다 check를 카운트 하고, 4개가 될때까지 진행
      check = 0; // check 초기화
      printf("< %dth epochs >\n", n); // epochs를 카운트
      for (int i = 0; i < 4; i++)
      {
         y = w1 * x[i][0] + w2 * x[i][1]; // y값, TH는 무시한다.

         Error = (target[CH][i] - y); // target값과 실제 출력 y 값 간의 차이를 저장할 변수

         E = 0.5 * ((Error)*(Error)); // 미분을 하기 위해 1/2을 곱하고 Error를 제곱

         printf("< 결과값 >\n");
         printf(" %lf\n %d\n", y, target[CH][i]); // y값과 AND, OR연산일 경우 예상되는 값 즉, target값을 출력
         printf(" w1 : %lf // w2 : %lf\n", w1, w2);
         if (y == target[CH][i]) // y값과 target값을 비교하여 카운트를 증가시킴, 카운트가 4이면 초기화 후 다시 카운트
         {
            check++;
         }
         else
         w1 = w1 + (a*(target[CH][i] - y)*x[i][0]); // W new = W old + a*(t-y)*(x vector), 가중치를 Gradient Descent한다.
         w2 = w2 + (a*(target[CH][i] - y)*x[i][1]); 
      }
      printf("E : %lf\n", E); //4개의 쌍 Total E값을 출력
      fprintf(out, "   %lf        %lf        %lf \n", w1, w2,E);// w1,w2,E 값을 txt data로 만든다.
      n = n + 1; //w1, w2의 값을 조정 후 epochs를 하나 더 카운트
      if ((n>100)||(E==0)|| (E <= Emin)) break;// 100번의 epochs 반복 한다, E가 0일 경우에도 종료, 중간과정에서 E의 최소값이 나올 수도 있으므로 일정 값보다 작을 경우 근사
   }
   fclose(out); // txt data 파일을 닫는다.
}

int main() {

   printf("w1 값을 입력하시오 : "); // 사용자로부터 w1값을 입력받는다.
   scanf("%lf", &w1);
   printf("w2 값을 입력하시오 : "); // 사용자로부터 w2값을 입력받는다.
   scanf("%lf", &w2);
   printf("a를 입력하시오(0 < a < 1) : "); // 사용자로 부터 a값을 입력받는다. a는 학습률
   scanf("%lf", &a);
   //과제에는 w1 = 0.5 , w2 = -0.4, a = 0.05 값 사용

   printf("연산 선택(0 = AND, 1 = OR) : "); // 연산을 선택한다 0이면 AND 연산, 1이면 OR연산
   scanf("%d", &CH);

   AND_OR(); // AND 또는 OR연산의 target과 실제 y을 비교하여 가중치를 변경

   printf("minimize E = %lf\n", E); //가장 마지막 100번째 epochs에서의 E값을 출력
   printf(" fixed w1 : %lf\n fixed w2 : %lf\n", w1, w2); // minimize E에 해당되는 w1과 w2를 출력한다.
   printf("end\n"); // 프로그램 끝

   return 0;
}