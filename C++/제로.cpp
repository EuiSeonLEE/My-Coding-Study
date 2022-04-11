#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <numeric>

using namespace std;


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<int> stk;
    int num = 0;
    int put_num = 0;
    int sum = 0;

    cin >> num;

    for(int a = 0; a < num; a++){
        cin >> put_num;
        if(put_num == 0) stk.pop();
        else stk.push(put_num);
    }
    while(!stk.empty()){
        sum += stk.top();
        stk.pop();
    }
    cout << sum <<"\n";
    return 0;
}
