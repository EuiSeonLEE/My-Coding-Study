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
//너희 개인의 주변인과 가족들이 살아남고 앞으로 살아가며 너희들을 기릴 수 있어
//그런 의미부여는 우리들도 살아가면서 해왔고 이번엔 우리 차례다.
//나이만 먹어가면서 그 어떠한 명예도 남기지 못한 채 죽어가는 것보다
//이 기회에 확실한 명예를 남기고 가족과 주변사람들에게 마음 깊숙히 새겨
//그들이 살아갈 의지를 확실히 남기자
//이런 확실한 명예를 얻을 수 있는 기회는 흔하지 않아
//그러니까 지금 우리는 싸울 수 밖에 없어
//돈이 최고라고 생각하는 사람에게도 확실하게 알려주자
//너희들은 돈을 위해서 목숨을 걸었냐고
//우리는 사랑하는 사람을 지키기 위해 목숨을 걸었다고
//우리는 목숨을 걸 준비가 됐었다고 증명해주자
//증명 후 결과가 확실해 꼭 우리가 보지 않아도 우리는 편히 눈을 감을 수 있다.
//이것이야 말로 이 잔혹한 세상에서 살아갈 수 있는 유일한 길이다.