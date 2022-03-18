#include <iostream>
#include <string>
#include <cctype> 
using namespace std;

int main(void){
    string DialStr = "";
    string DialNumber[8] = {"ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
    string BigAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    bool StrAccess = true;
    int CallTime = 0;

    while(1){
        cin >> DialStr;
        
        if(DialStr.size() >= 2 && DialStr.size() <= 15){
            for(int a = 0; a < DialStr.size(); a++){
                if(BigAlphabet.find(DialStr.substr(a,1)) == -1){
                    //cout << "Please " << a <<"st bigalphabet typing" <<endl;
                    StrAccess = false;
                    a = DialStr.size() - 1;
                }
                else  StrAccess = true;
            }
        }
        //else cout << "Please Retyping" <<endl;

        if(StrAccess) break;
    }
    
    for(int b = 0; b < DialStr.size(); b++){
        for(int c = 0; c < 8; c++){
            if(DialNumber[c].find(DialStr.substr(b,1)) != -1){
                CallTime += c + 3;
            }
        }
    }
    cout<< CallTime <<endl;
    return 0;
}