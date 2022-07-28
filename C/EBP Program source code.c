#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>      //time(

#pragma warning(disable : 4996)
#pragma warning(disable : 4244)


#define Learing_test 1 //test(0) or 학습(1)
#define W_select 0 //Weight 설정 기존 데이터(0) or rand(1)
#define W_epoch 200 //몇 번째 epoch의 Weight로 설정(TEST할 때 만 씀)
int allLine = 110; //input 라인 몇 줄 인지?
int InputNUM = 10;
int OutputNUM = 1;
int HLnum = 4;
int bias = 1;
int Epoch = 300;
double ETA = 0.01; //Learning Gain

int HLneurons[10] = { 15, 15, 15, 15, 15, 15, 15, 15, 15, 15};

double HLw[10][15][15];
double w_in[10][15];
double w_out[15][2]; // hidden layer - output layer w
double w_bias[10][15]; //bias - hidden layer1 w
double w_out_bias[2]; //bias - hidden layer2 w, bias - output layer w

double target[2] = { 0.0, };
double E = 0.0, evaErr = 0.0;
int cnt = 0;
int ErrCount = 0, WeightCount = 0;

FILE* weightWrite, * WeightRead;
void EBP(double u_in[], double u[][15], double u_out[], double Delta[][15], double Delta_out[], double E, double target[]){
	double s[10][15] = { 0.0, };
				double s_out[2] = { 0.0, };
				
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
					//E += fabs(target[0] - u_out[0]);
					E += (((target[0] - u_out[0]) * (target[0] - u_out[0]))/2);
				}
				else if (OutputNUM == 2) {
					//E += (fabs(target[0] - u_out[0]) + fabs(target[1] - u_out[1])) / 2;
					E += (((target[0] - u_out[0]) * (target[0] - u_out[0]) + (target[1] - u_out[1]) * (target[1] - u_out[1]))/2);
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
int GridTest(double u_in[], double t[], int evaluation) {
	double s[10][15] = { 0.0, };
	double s_out[2] = { 0.0, };
	double u[10][15] = { 0.0, }; //(hidden layer1)output U
	double u_out[2] = { 0.0, };//(hidden layer2)output U
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
		//evaErr += fabs(target[0] - u_out[0]);
		evaErr += (((target[0] - u_out[0]) * (target[0] - u_out[0]))/2);
	}
	else if (OutputNUM == 2) {
		//evaErr += (fabs(target[0] - u_out[0]) + fabs(target[1] - u_out[1])) / 2;
		evaErr += (((target[0] - u_out[0]) * (target[0] - u_out[0]) + (target[1] - u_out[1]) * (target[1] - u_out[1]))/2);
	}

	int y = 0;

	if (u_out[0] > 0.5 || fabs(u_out[0] - 0.5) < 0.000001) y = 1;
	else y = 0;

	//evaluation Test 가 아니고 격자테스트의 경우에는, y 값을 리턴한다.
	if (evaluation == 0) return y;	

	return 0;
}

double rate() {
	return (double)(((rand() % 31) - 15.0) / 10.0);
}

void writeChoose(int write, double* weight_tmp) {
	if (write == 1) {
		fprintf(weightWrite, "%lf\n", *weight_tmp);
	}
	else if (write == 2) {
		fscanf(WeightRead, "%lf\n", weight_tmp);
		if (fabs(*weight_tmp) < 0.3) *weight_tmp = 0;
	}
	else *weight_tmp = rate();
}

void set_w(int write) { //초기 weight는 랜덤값 지정
	srand(0606);

	for (int i = 0; i < InputNUM; i++) {
		for (int j = 0; j < HLneurons[0]; j++) {
			writeChoose(write, &w_in[i][j]);
		}
	}

	for (int i = 0; i < HLnum - 1; i++) {
		for (int j = 0; j < HLneurons[i]; j++) {
			for (int k = 0; k < HLneurons[i + 1]; k++) {
				writeChoose(write, &HLw[i][j][k]);
			}
		}
	}

	for (int i = 0; i < OutputNUM; i++) {
		for (int j = 0; j < HLneurons[HLnum - 1]; j++) {
			writeChoose(write, &w_out[i][j]);
		}
	}

	for (int i = 0; i < HLnum; i++) {
		for (int j = 0; j < HLneurons[i]; j++) {
			writeChoose(write, &w_bias[i][j]);
		}
	}

	for (int i = 0; i < OutputNUM; i++) {
		writeChoose(write, &w_out_bias[i]);
	}
}

void getEvaRealData(FILE* fin, FILE* eva, FILE* realData) {
	double x_tmp[10], t_tmp[2];
	int randIn = 0;

	while (fscanf(fin, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n", &x_tmp[0], &x_tmp[1], &x_tmp[2], &x_tmp[3], &x_tmp[4],
		&x_tmp[5], &x_tmp[6], &x_tmp[7], &x_tmp[8], &x_tmp[9], &t_tmp[0]) != EOF) {
		if (randIn < allLine / 10) { //?
			fprintf(eva, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n", x_tmp[0], x_tmp[1], x_tmp[2], x_tmp[3], x_tmp[4],
				x_tmp[5], x_tmp[6], x_tmp[7], x_tmp[8], x_tmp[9], t_tmp[0]);
			randIn++;
		}
		else fprintf(realData, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n", x_tmp[0], x_tmp[1], x_tmp[2], x_tmp[3], x_tmp[4],
			x_tmp[5], x_tmp[6], x_tmp[7], x_tmp[8], x_tmp[9], t_tmp[0]);
	}

	fclose(realData);
	fclose(eva);
}
void get_parameter(FILE* fd_arch, FILE* fd_para){
	while(fd_arch != EOF){
		fscanf(fd_arch, "%d ", &InputNUM);
		fscanf(fd_arch, "%d ", &HLnum);
		for(int a = 0; a < HLnum; a++){
			fscanf(fd_arch, "%d ", &HLneurons[a]);
		}
		fscanf(fd_arch, "%d\n", OutputNUM);
	}
	while(fd_para != EOF){
		fcanf(fd_para, "%lf %d %d %d %d\n", &ETA, &Epoch, &ErrCount, &WeightCount, &bias);
	}
}
int main() {
	int Learing_Test = Learing_test, w_select = W_select, w_epoch = W_epoch;
	double x[10] = {0.0,} ,x1 ,x2 , t = 0;
	int epochs = 1;
	time_t current;
	struct tm* timer;

	FILE* fd_arch;
	FILE* fd_para;
	FILE* fd_out;
	FILE* fd_err;

	if ((fd_arch = fopen("architecture.dat", "r")) == NULL) //학습구조의 값을 기록할 파일
	{
		printf("can't find file \n"); // 읽지 못하면 에러
		return -1;
	}
	fscanf(fd_arch, "%d, %d, %d, %d, %d, %d", &InputNUM, &HLneurons[0], &HLneurons[1], &HLneurons[2], &HLneurons[3], &OutputNUM);
	if ((fd_para = fopen("parameter.dat", "r")) == NULL) //LG, error저장 epoch, weight저장 epoch
	{
		printf("can't find file \n"); // 읽지 못하면 에러
		return -1;
	}
	fscanf(fd_para, "%lf\n%d\n%d", &ETA, &ErrCount, &WeightCount);
	fclose(fd_arch);
	fclose(fd_para);
	printf("%d, %d, %d, %d, %d\n", InputNUM, HLneurons[0], HLneurons[1], HLneurons[2], OutputNUM);
	printf("%lf\n%d\n%d\n", ETA, ErrCount, WeightCount);

	FILE* fd_in;
	if ((fd_in = fopen("Training_data(0606).txt", "r")) == NULL)
	{
		printf("can't find file \n"); // 읽지 못하면 에러
		return -1;
	}

	/*FILE* eva = fopen("evaData.txt", "w"), * realData = fopen("realData.txt", "w");
	getEvaRealData(fd_in, eva, realData);
	realData = fopen("realData.txt", "r");
	eva = fopen("evaData.txt", "r");*/

	if ((fd_out = fopen("outputdata.txt", "w")) == NULL) //Error의 값을 기록할 파일
	{
		printf("can't find file \n"); // 읽지 못하면 에러
		return -1;
	}
	if ((fd_err = fopen("errdata.txt", "w")) == NULL) //디테일한 Error의 값을 기록할 파일
	{
		printf("can't find file \n"); // 읽지 못하면 에러
		return -1;
	}
	printf("test(0) or 학습(1) : %d\n", Learing_Test);
	//scanf("%d", &Learing_Test);
	if (Learing_Test == 1) {
		printf("Weight 설정 기존 데이터(0) or rand(1) :%d\n ",w_select);
		//scanf("%d", &w_select);

		if (w_select == 1) {
			set_w(0); //0이면 random으로 weight 설정
		}
		else if (w_select == 0) {
			printf("Weight를 설정하세요! : %d\n", w_epoch);
			//scanf("%d", &w_epoch);

			//입력한 epoch 번째의 weight 를 읽어오고
			char tmp[200];
			sprintf(tmp, "weight%d.dat", w_epoch);
			WeightRead = fopen(tmp, "r");

			set_w(2); //읽어온 weight 로 초기화한다.

			//test를 위해서 맨처음의 weight 값을 기록한다.
			weightWrite = fopen("EarlyWeight.dat", "w");
			set_w(1); //write를 해줄때는 1번이다.

			fclose(weightWrite);
			fclose(WeightRead);
		}
	}
	else if (Learing_Test == 0) {
		printf("Test할 Weight를 입력하세요! : %d", w_epoch);
		//scanf("%d", &w_epoch);

		char tmp[200];
		sprintf(tmp, "weight%d.dat", w_epoch);

		WeightRead = fopen(tmp, "r");

		set_w(2); //weight 를 읽어온 weight 로 설정한다.

		fclose(WeightRead);
	}

	/*srand(time(NULL));
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
	}*/
	if(Learing_Test == 1){
		while (cnt < Epoch)
		{
			double u_in[10] = { 0.0, };
			double u[10][15] = { 0.0, }; //(hidden layer1)output U
			double u_out[2] = { 0.0, };//(hidden layer2)output U

			double Delta[10][15] = { 0.0, }; // (hidden layer1)delta
			double Delta_out[2] = { 0.0, };// (hidden layer2, output layer) delta
			double E = 0.0; //error

			cnt++;

			/*FILE* realData;
			if ((realData = fopen("realData.txt", "r")) == NULL)
			{
				printf("can't find file \n"); // 읽지 못하면 에러
				return -1;
			}*/
			rewind(fd_in);
			
			
			while (fscanf(fd_in, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n", &u_in[0], &u_in[1], &u_in[2], &u_in[3], &u_in[4], &u_in[5], &u_in[6], &u_in[7], &u_in[8], &u_in[9], &target[0]) != EOF) {
				EBP(u_in, u, u_out, Delta, Delta_out, E, target);
			}
			current = time(NULL);
			timer = localtime(&current);

			fprintf(fd_out, "%lf\n", E);
			
			printf("%dth : epochs - Error = %lf\n", epochs, E); //epochs횟수 구할 때
			epochs++;
			fclose(fd_in);

			if(cnt % ErrCount == 0) {
				fprintf(fd_err, "%d %lf %d:%d:%d:%d:%d:%d\n",epochs ,E ,timer->tm_year + 1900, timer->tm_mon + 1, timer->tm_mday, timer->tm_hour,timer->tm_min,timer->tm_sec);
			}
			if(cnt % WeightCount == 0){
				char W_filename[200];
				sprintf(W_filename, "weight%d.dat", cnt);
				weightWrite = fopen(W_filename, "w");
				set_w(1);

				fclose(weightWrite);
			}
			/*if (cnt % 500 == 0) { //w의 변화 100번의 1번씩 cmd창에 격자화
			for (double x2 = 3.0; x2 >= -3.0; x2 -= 0.1) {
				printf("\n");
				for (double x1 = -3.0; x1 <= 3.0; x1 += 0.1) {
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
					else printf(". ");
				}
			}
			printf("\n");
			Sleep(150);
			system("cls"); //영상으로 제작할시 사용
			}*/
		}
		fclose(fd_out);
		fclose(fd_err);
	}
	else if(Learing_Test == 0){
		FILE* testData = fopen("Test_data(0606).txt", "r"), * outputData = fopen("output.dat", "w");
		//기댓값 있으면 %lf 및 ,&t[0] 추가!
		while (fscanf(testData, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n", &x[0], &x[1], &x[2], &x[3], &x[4],
			&x[5], &x[6], &x[7], &x[8], &x[9], &target[0]) != EOF) {
			//fprintf(outputData, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %d\n", x[0], x[1], x[2], x[3], x[4],
			//	x[5], x[6], x[7], x[8], GridTest(x, t, 0));
			fprintf(outputData, "%d\n", GridTest(x, target, 0));
		}
		fclose(outputData);
		fclose(testData);
	}
	/*if (Learing_Test == 1) {
	FILE* evErrFile = fopen("evaErr.txt", "w");
		for (int i = WeightCount; i <= Epoch; i += WeightCount) {

			char WeightFileName[200];
			sprintf(WeightFileName, "C:\\ML_test\\weight\\weight%d.dat", i);

			WeightRead = fopen(WeightFileName, "r");

			set_w(2);

			fclose(WeightRead);

			rewind(eva);
			evaErr = 0;
			while (fscanf(eva, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n", &x[0], &x[1], &x[2], &x[3], &x[4],
				&x[5], &x[6], &x[7], &x[8], &x[9], &target[0]) != EOF) {
				//evaData.txt 파일에서 테스트 파일을 읽어와서 Error 값을 구한다.
				GridTest(x, target, 1);
			}
			fprintf(evErrFile, "%d %lf\n", i, evaErr / (allLine / 10));
		}
	fclose(evErrFile);
	}*/
	//fclose(eva);
	//fclose(realData);
	fclose(fd_in);
}