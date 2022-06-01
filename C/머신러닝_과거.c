#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>      //time()
#include<Windows.h>

#pragma warning(disable : 4996)
#pragma warning(disable : 4244)
#define InputNUM 2
#define OutputNUM 1
#define HLnum 5
#define bias 1
#define ETA 0.5

int HLneurons[10] = { 8, 10, 5, 4, 12, 2, 7, 13, 3, 4 };

double HLw[10][15][15];
double w_in[10][15];
double w_out[15][2]; // hidden layer - output layer w
double w_bias[10][15]; //bias - hidden layer1 w
double w_out_bias[2]; //bias - hidden layer2 w, bias - output layer w

double target[2] = { 0.0, };
double E = 0.0;
int cnt = 0;
int outputnum = OutputNUM;

int main()
{
	FILE* fd_out;
	if ((fd_out = fopen("outputdata.txt", "w")) == NULL) //Error의 값을 기록할 파일
	{
		printf("can't find file \n"); // 읽지 못하면 에러
		return -1;
	}
	double x1, x2, t = 0;
	int epochs = 1;

	srand(time(NULL));
	for (int a = 0; a < InputNUM; a++) {
		for (int b = 0; b < HLneurons[0]; b++) {
			w_in[a][b] = (double)(((rand() % 31) - 15.0) / 10.0);
			//printf("w_in:%d:%d = %lf\n",a,b, w_in[a][b]);
		}
	}
	srand(time(NULL));
	for (int a = 0; a < HLnum - 1; a++) {
		for (int b = 0; b < 15; b++) {
			for (int c = 0; c < 15; c++) {
				HLw[a][b][c] = (double)(((rand() % 31) - 15.0) / 10.0);
				//printf("HLw:%d:%d:%d = %lf\n", a, b, c, HLw[a][b][c]);
			}
		}
	}
	srand(time(NULL));
	for (int a = 0; a < 15; a++) {
		for (int b = 0; b < OutputNUM; b++) {
			w_out[a][b] = (double)(((rand() % 31) - 15.0) / 10.0);
			//printf("w_out:%d:%d = %lf\n", a, b, w_out[a][b]);
		}
	}
	srand(time(NULL));
	for (int a = 0; a < HLnum; a++) {
		for (int b = 0; b < 15; b++) {
			w_bias[a][b] = (double)(((rand() % 31) - 15.0) / 10.0);
			//printf("w_bias:%d:%d = %lf\n", a, b, w_bias[a][b]);
		}
	}
	srand(time(NULL));
	for (int a = 0; a < OutputNUM; a++) {
		w_out_bias[a] = (double)(((rand() % 31) - 15.0) / 10.0);
		//printf("w_out_bias:%d = %lf\n", a, w_out_bias[a]);
	}

	while (cnt < 100000)
	{
		double u_in[10] = { 0.0, };
		double u[10][15] = { 0.0, }; //(hidden layer1)output U
		double u_out[2] = { 0.0, };//(hidden layer2)output U

		double Delta[10][15] = { 0.0, }; // (hidden layer1)delta
		double Delta_out[2] = { 0.0, };// (hidden layer2, output layer) delta
		double E = 0.0; //error


		E = 0.0;
		cnt++;



		FILE* fd_in;
		if ((fd_in = fopen("inputdata.txt", "r")) == NULL)
		{
			printf("can't find file \n"); // 읽지 못하면 에러
			return -1;
		}

		while (fscanf(fd_in, "%lf %lf %lf\n", &x1, &x2, &t) != EOF) {

			double s[10][15] = { 0.0, };
			double s_out[2] = { 0.0, };
			u_in[0] = x1;
			u_in[1] = x2;
			target[0] = t;

			// 만약 HLnum = 4
			// HLneurons[HLnum] = {2, 3, 4, 5} 라고 한다면
			for (int a = 0; a < HLneurons[0]; a++) {
				s[0][a] += bias * w_bias[0][a]; //바이어스 2개만 더해짐
				for (int b = 0; b < InputNUM; b++) {
					s[0][a] += u_in[b] * w_in[b][a];
					//printf("s%d:%d = %lf\n", a, b, s[0][a]);
				}
				u[0][a] = 1.0 / (1.0 + exp(-s[0][a]));
				//printf("u%d = %lf\n",a, u[0][a]);
			}

			for (int a = 0; a < HLnum - 1; a++) {
				for (int b = 0; b < HLneurons[a + 1]; b++) {
					s[a + 1][b] += bias * w_bias[a + 1][b];
					for (int c = 0; c < HLneurons[a]; c++) {
						s[a + 1][b] += HLw[a][b][c] * u[a][c];
						//printf("s%d:%d = %lf\n", a + 1, a, s[a + 1][b]);
					}
					u[a + 1][b] = 1.0 / (1.0 + exp(-s[a + 1][b]));
					//printf("u%d = %lf\n",a+1, u[a+1][b]);

				}
			}

			for (int a = 0; a < OutputNUM; a++) {
				s_out[a] += bias * w_out_bias[a];
				for (int b = 0; b < HLneurons[HLnum - 1]; b++) {
					s_out[a] += w_out[b][a] * u[HLnum - 1][b];
					//printf("s_out%d = %lf\n", a, s_out[a]);
				}
				u_out[a] = 1.0 / (1.0 + exp(-s_out[a]));
				//printf("u_out%d = %lf\n", a, u_out[a]);
			}
			/*========================E의 변화==========================*/
			if (OutputNUM == 1) {
				E += fabs(target[0] - u_out[0]);
			}
			else if (OutputNUM == 2) {
				E += (fabs(target[0] - u_out[0]) + fabs(target[1] - u_out[1])) / 2;
			}
			/*========================Delta 구하기=========================*/
			for (int a = 0; a < OutputNUM; a++) {
				Delta_out[a] = u_out[a] * (1.0 - u_out[a]) * (target[a] - u_out[a]);
				//printf("Delata_out %d = %lf\n",a, Delta_out[a]);
			}


			for (int a = 0; a < HLneurons[HLnum - 1]; a++) {
				double sum = 0.0;
				for (int b = 0; b < OutputNUM; b++) {
					sum += w_out[a][b] * Delta_out[b];
				}
				Delta[HLnum - 1][a] = u[HLnum - 1][a] * (1.0 - u[HLnum - 1][a]) * sum;
				//printf("Delata %d:%d = %lf\n",HLnum-1,a, Delta[HLnum-1][a]);
			}

			for (int a = HLnum - 1; a > 0; a--) {
				for (int b = 0; b < HLneurons[a - 1]; b++) {
					double sum = 0.0;
					for (int c = 0; c < HLneurons[a]; c++) {
						sum += Delta[a][c] * HLw[a - 1][c][b];
					}
					Delta[a - 1][b] = u[a - 1][b] * (1.0 - u[a - 1][b]) * sum;
					//printf("Delata %d:%d = %lf\n",a-1,b, Delta[a-1][b]);
				}
			}
			/*========================w의 변화==========================*/
			for (int a = 0; a < InputNUM; a++) {
				for (int b = 0; b < HLneurons[0]; b++) {
					w_in[a][b] += u_in[a] * Delta[0][b] * ETA;
					//printf("w_in %d:%d = %lf\n", a, b, w_in[a][b]);

				}
			}
			for (int a = HLnum - 1; a > 0; a--) {
				for (int b = 0; b < HLneurons[a - 1]; b++) {
					for (int c = 0; c < HLneurons[a]; c++) {
						HLw[a - 1][c][b] += u[a - 1][b] * Delta[a][c] * ETA;
						//printf("HLw %d:%d:%d = %lf\n", a, b, c, HLw[a][b][c]);
					}
				}
			}
			for (int a = 0; a < HLneurons[HLnum - 1]; a++) {
				for (int b = 0; b < OutputNUM; b++) {
					w_out[a][b] += u[HLnum - 1][a] * Delta_out[b] * ETA;
					//printf("w_out %d:%d = %lf\n", a,b, w_out[a][b]);
				}
			}

			for (int a = HLnum - 1; a >= 0; a--) {
				for (int b = 0; b < HLneurons[a]; b++) {
					w_bias[a][b] += Delta[a][b] * bias * ETA;
					//printf("w_bias %d:%d = %lf\n", a, b, w_bias[a][b]);
				}
			}
			for (int a = 0; a < OutputNUM; a++) {
				w_out_bias[a] += Delta_out[a] * bias * ETA;
				//printf("w_out_bias %d = %lf\n", a, w_out_bias[a]);
			}



		}

		fprintf(fd_out, "%lf\n", E);
		printf("%dth : epochs - Error = %lf\n", epochs, E); //epochs횟수 구할 때
		epochs++;
		fclose(fd_in);

		if (cnt % 500 == 0) { //w의 변화 100번의 1번씩 cmd창에 격자화
		   for (double x2 = 1.5; x2 >= -1.5; x2 -= 0.1) {
			  printf("\n");
			  for (double x1 = -2; x1 <= 3; x1 += 0.1) {
				  double s1[10][15] = { 0.0, };
				  double s_out1[2] = { 0.0, };
				  double u_in1[10] = { 0.0, };
				  u_in1[0] = x1;
				  u_in1[1] = x2;
				  target[0] = t;

				  // 만약 HLnum = 4
				  // HLneurons[HLnum] = {2, 3, 4, 5} 라고 한다면
				  for (int a = 0; a < HLneurons[0]; a++) {
					  s1[0][a] += bias * w_bias[0][a]; //바이어스 2개만 더해짐
					  for (int b = 0; b < InputNUM; b++) {
						  s1[0][a] += u_in1[b] * w_in[b][a];
						  //printf("s%d:%d = %lf\n", a, b, s[0][a]);
					  }
					  u[0][a] = 1.0 / (1.0 + exp(-s1[0][a]));
					  //printf("u%d = %lf\n",a, u[0][a]);
				  }

				  for (int a = 0; a < HLnum - 1; a++) {
					  for (int b = 0; b < HLneurons[a + 1]; b++) {
						  s1[a + 1][b] += bias * w_bias[a + 1][b];
						  for (int c = 0; c < HLneurons[a]; c++) {
							  s1[a + 1][b] += HLw[a][b][c] * u[a][c];
							  //printf("s%d:%d = %lf\n", a + 1, a, s[a + 1][b]);
						  }
						  u[a + 1][b] = 1.0 / (1.0 + exp(-s1[a + 1][b]));
						  //printf("u%d = %lf\n",a+1, u[a+1][b]);

					  }
				  }

				  for (int a = 0; a < OutputNUM; a++) {
					  s_out1[a] += bias * w_out_bias[a];
					  for (int b = 0; b < HLneurons[HLnum - 1]; b++) {
						  s_out1[a] += w_out[b][a] * u[HLnum - 1][b];
						  //printf("s_out%d = %lf\n", a, s_out[a]);
					  }
					  u_out[a] = 1.0 / (1.0 + exp(-s_out1[a]));
				  }
				 if (u_out[OutputNUM-1] >= 0.5)printf("O ");
				 else printf("x ");
			  }
		   }
		   printf("\n");
		   Sleep(150);
		   system("cls"); //영상으로 제작할시 사용
		}
	}
	

	fclose(fd_out);

	getchar();
}