#include <iostream>
#include <string>
using namespace std;

int main(void){
    string S = "";
    
    cin >> S;
    S.resize(100);   //100byte로 문자길이 맞추기
    S.shrink_to_fit(); //100byte에 맞는 메모리 자동 할당
    cout << S << endl;
    for(char c = 97; c < 123;c++){
        for(int a = 0;a < S.size();a++){
            if(S.operator[](a) == c){
                cout << a <<" ";
                c++;
                a = 0;
            }
            if(a == (S.size()-1)){
                cout << -1 <<" ";
            }
            
        }
    }
   

}