#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void){
    string S, P;
    
    int a = 0, Cnt = 0;
    
    getline(cin, S);
    cout << S <<endl;
    cout << S.size() <<endl;
    int b;
  


    while(1){
        b = S.find(" ", a);
        cout << P.find(" ", a) <<endl;
        if(b > -1){
            
            P = S.substr(a, S.find(" ", a));
            a = S.find(" ", a);
            cout << a <<endl;
            if(P.size() > 0){
                Cnt++;
                
            }
        }
        
        S = S.substr(a+1);
        cout << "S = " << S<<endl;
        if(S.size() < 1) break;
    }
    cout << Cnt <<endl;
    return 0;
}