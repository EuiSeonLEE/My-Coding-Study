#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <math.h>
using namespace std;

vector<int> Split(string input, string delimiter){
    vector<int> buffer;
    long long pos = 0;
    string token = "";
    while((pos = input.find(delimiter)) != string::npos){
        token = input.substr(0, pos); //token에 자른 문자 넣어주고
        //cout << token << "\n";
        buffer.push_back(std::stoi(token));      //buffer배열에 넣어주고
        //cout << token << "\n";
        input.erase(0, pos + delimiter.size()); //input문자열을 처음부터 (pos + 끊을 문자열)크기만큼 지움
    }
    buffer.push_back(std::stoi(input)); //마지막 남은 문자열 넣어줌
    //cout << buffer[buffer.size() - 1] << "\n";
    return buffer;
}

int main(void){
    //과목 5개 입력
    //과목당 문제푼 학생 수 입력
    //학생 수 만큼 각 점수 입력
    vector<int> StudentScore;

    //각 과목당 학생수만큼 평균값 도출
    int TestcaseNum = 0;
    string GetScore = "";

    cin >> TestcaseNum;
    cin.ignore();
    for(int a = 0; a < TestcaseNum; a++){
        int num = 0;
        getline(cin, GetScore);
        //StudentScore[a] = Split(GetScore, " ");
        StudentScore = Split(GetScore, " ");
        double Avr = double(accumulate(StudentScore.begin()+1, StudentScore.end(), 0)) / double(StudentScore[0]);
        for(int c = 0; c < StudentScore[0]; c++){
            if(double(StudentScore[c + 1]) > Avr){
                num++;
            }
        }
        cout.setf(ios::showpoint); //소수점 나머지 부분을 0으로 처리
        cout.precision(5); //5자리까지 값출력
        cout  << round((num/double(StudentScore[0])*100) * 1000) / 1000 << "%" << "\n"; 
    }
    
    return 0;
}
