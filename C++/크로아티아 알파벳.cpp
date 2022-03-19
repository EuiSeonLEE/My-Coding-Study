#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void){
    string CroatiaStr = "";
    string CroatiaAlphabet[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    int Result = 0;
    
    cin >> CroatiaStr;
    
    for(int a = 0; a < 8; a++){
        while(1){
            if(CroatiaStr.find(CroatiaAlphabet[a]) != -1){
                Result++;
                CroatiaStr = CroatiaStr.replace(CroatiaStr.find(CroatiaAlphabet[a]),CroatiaAlphabet[a].size(),"");
            }
            else break;
        }
    }
    Result += CroatiaStr.size();

    cout << Result <<endl;
    return 0;
}