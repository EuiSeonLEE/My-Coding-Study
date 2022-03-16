#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void){
    string S, P;
    
    int a = 0, Cnt = 0;
    
    getline(cin, S);
    cout << S << endl;
    cout << S.size() << endl;
    int b;
  


    while(1){
        a = S.find(" ");
        cout << "a = " << a <<endl;
        
        if(a > -1){
            
            P = S.substr(0, S.find(" "));
            cout << " P =" << P <<endl; 
            if(P.size() > 0){
                Cnt++;
            }
            S = S.substr(a+1);
        }
        else {
            P = S;
            cout << " P =" << P <<endl; 
            if(P.size() > 0) {
                Cnt++;
            }
            break;
        }
    }
    cout << Cnt <<endl;
    return 0;
}