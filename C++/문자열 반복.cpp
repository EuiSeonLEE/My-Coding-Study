#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void){
    string S[1000] = {"",};
    string P[1000] = {"",};
    
    int R[] = {0,};
    int T = 0;
    
    while(T < 5){
        while(1){
        cin >> R[T];
            if(R[T]>=1 && R[T]<=8){
                break;
            }
        cout << "<<Retyping>>"<< endl;
        }
        cin >> S[T];
        S[T].resize(20);   //20byte로 문자길이 맞추기
        S[T].shrink_to_fit(); //20byte에 맞는 메모리 자동 할당(31byte할당)
        
        for(int a = 0;a < S[T].size();a++){
            for(int b = 0;b < R[T];b++){
                P[T] += S[T].substr(a,1);
            }
        }
    
        T++;
    }

    for(int x = 0; x < 5;x++){        
        cout << P[x] << endl;
    }
    return 0;
}