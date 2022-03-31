#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//#include <stdio.h>
using namespace std;

int main(void){
    vector<short> Arr;
    string Num = "";
    
    cin >> Num;
    
    for(int a = 0; a < Num.size(); a++){
        Arr.push_back(stoi(Num.substr(a,1)));
    }
    sort(Arr.begin(),Arr.end());
    
    for(short b = Arr.size() - 1; b >= 0; b--){
        printf("%d",Arr[b]); //cout은 느리다...
    }
    return 0;
}
