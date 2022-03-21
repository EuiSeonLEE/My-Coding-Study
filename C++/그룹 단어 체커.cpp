#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void){
    int WordNum = 0;
    int Cnt = 0;
    int Result = 0;
    string Words[100] = {"",};

    while(1){
        cin >> WordNum; //단어 입력 개수 선정
        if(WordNum <= 100) break;
    }
    for(int a = 0; a < WordNum; a++){ //갯수대로 순서대로 단어입력
        cin >> Words[a]; 
    }
    for(int b = 0; b < WordNum; b++){
        while(1){
            //cout << b << " : " <<Words[b].find(Words[b].substr(Cnt,1), Cnt+1)<<" : "<<Words[b].find(Words[b].substr(Cnt,1),Cnt)<<endl;
            //b번째 단어의 Cnt번째 알파벳이 다음 번째에도 존재한다면
            if(Words[b].find(Words[b].substr(Cnt,1), Cnt+1) != -1){  
                //b번째 단어의 Cnt번째 알파벳이 연속허자 않는다면
                if(Words[b].find(Words[b].substr(Cnt,1), Cnt+1) > Words[b].find(Words[b].substr(Cnt,1),Cnt) + 1){
                    Cnt = 0;
                    break;
                }
                else Cnt++;
            }
            else Cnt++;

            if(Cnt == Words[b].size()){//Cnt가 b번째 단어 길이와 같아지면
                Cnt = 0;
                Result++; //b번째 단어는 연속단어로 인정
                break;
            }
        }
    }
    cout << Result << endl;
    return 0;
}