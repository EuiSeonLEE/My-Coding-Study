#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void){
    string A;
    string B;
    string SangsuA = "";
    string SangsuB = "";

    
    cin >> A >> B;
    
    A.resize(3);   //100byte로 문자길이 맞추기
    A.shrink_to_fit(); //100byte에 맞는 메모리 자동 할당
    B.resize(3);   //100byte로 문자길이 맞추기
    B.shrink_to_fit(); //100byte에 맞는 메모리 자동 할당
    while(1){
        if(A.size() <= 0) break;
        SangsuA += A.substr(A.size() - 1);
        A.pop_back();
    }

    while(1){
        if(B.size() <= 0) break;
        SangsuB += B.substr(B.size() - 1);
        B.pop_back();
    }
    
    //cout << SangsuA << " " << SangsuB << endl;

    if(stoi(SangsuA) >= stoi(SangsuB)) cout << stoi(SangsuA) << endl;
    else cout << stoi(SangsuB) << endl;

    return 0;
}