#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main(void){
    //과목 5개 입력
    //과목당 문제푼 학생 수 입력
    //학생 수 만큼 각 점수 입력

    //각 과목당 학생수만큼 평균값 도출
    int TestcaseNum = 0;
    int StudentNum = 0;
    int Cnt = 0;
    int AvrUp = 0;
    int Testcase[100][1000] = {{0,},};
    double StudentAvr[100] = {0,};
    string GetStudent = "";
    
    cin >> TestcaseNum;
    cin.ignore();
    while(1){
        AvrUp = 0;
        getline(cin,GetStudent);
        //cout << GetStudent.size()<<endl;
        int idx = 0;
        int ScoreCnt = 0;
        for(int i = 0; i < GetStudent.size();i++){
            if(GetStudent[i] == ' '){
                if(ScoreCnt == 0) {
                    StudentNum = stoi(GetStudent.substr(idx,i-idx));
                    idx = i + 1;
                    ScoreCnt++;
                }
                else {
                    Testcase[Cnt][ScoreCnt - 1] = stoi(GetStudent.substr(idx,i-idx));
                    idx = i + 1;
                    ScoreCnt++;
                }
            }
        }
        Testcase[Cnt][ScoreCnt - 1] = stoi(GetStudent.substr(idx));
        //cout << StudentNum<<":" << Testcase[Cnt][0] <<":"<< Testcase[Cnt][1] << endl;
        for(int a = 0; a < StudentNum; a++){
            //cin >> Testcase[Cnt][a];
            StudentAvr[Cnt] += Testcase[Cnt][a];
        }
        StudentAvr[Cnt] = double(StudentAvr[Cnt])/double(StudentNum);
        for (int b = 0; b < StudentNum; b++){
            if(StudentAvr[Cnt] <= double(Testcase[Cnt][b])){
                AvrUp++;
            }
        }
        //cout << "StudentAvr[Cnt]" << StudentAvr[Cnt] <<endl;
        StudentAvr[Cnt] = (double(AvrUp) / double(StudentNum)) * 100.0;
        
        Cnt++;
        if(Cnt == TestcaseNum) break;
    }
    for(int b = 0; b < TestcaseNum; b++){
        cout.setf(ios::showpoint); //소수점 나머지 부분을 0으로 처리
        cout.precision(5); //5자리까지 값출력
        cout  << round(StudentAvr[b] * 1000) / 1000 << "%" << endl; 
        //cout << round(StudentAvr[b] * 1000) / 1000 << "%" << endl; 
    }
    return 0;
}
//너희 개인의 주변인과 가족들이 살아남고 앞으로 살아가며 너희들을 기릴 수 있어
//그런 의미부여는 우리들도 살아가면서 해왔고 이번엔 우리 차례다.
//나이만 먹어가면서 그 어떠한 명예도 남기지 못한 채 죽어가는 것보다
//이 기회에 확실한 명예를 남기고 가족과 주변사람들에게 마음 깊숙히 새겨
//그들이 살아갈 의지를 확실히 남기자
//이런 확실한 명예를 얻을 수 있는 기회는 흔하지 않아
//그러니까 지금 우리는 싸울 수 밖에 없어
//돈이 최고라고 생각하는 사람에게도 확실하게 알려주자
//너희들은 돈을 위해서 목숨을 걸었냐고
//우리는 사랑하는 사람을 지키기 위해 목숨을 걸었다고
//우리는 목숨을 걸 준비가 됐었다고 증명해주자
//증명 후 결과가 확실해 꼭 우리가 보지 않아도 우리는 편히 눈을 감을 수 있다.
//이것이야 말로 이 잔혹한 세상에서 살아갈 수 있는 유일한 길이다.