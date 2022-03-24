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
        cout.setf(ios::showpoint);
        cout.precision(5);
        cout  << round(StudentAvr[b] * 1000) / 1000 << "%" << endl; 
        //cout << round(StudentAvr[b] * 1000) / 1000 << "%" << endl; 
    }
    return 0;
}