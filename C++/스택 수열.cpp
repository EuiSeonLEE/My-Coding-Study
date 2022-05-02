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

    vector<int> array;
    
    stack<int> stk;
    vector<char> result;
    int cnt = 0, array_cnt = 0;
    int num = 0;
    string put_wall = "";
    
    //중간고사 종료 D-DAY
    cin >> cnt;
    for(int a = 0; a < cnt; a++){
        cin >> num;
        array.push_back(num);
    }//{4,3,6,8,7,5,2,1} 
    
    for(int b = 1; b <= cnt; b++){
        stk.push(b);
        result.push_back('+');
        while(!stk.empty() && stk.top() == array[array_cnt]){
            stk.pop();
            result.push_back('-');
            array_cnt++;
        }
    }
    if(!stk.empty()) cout << "NO\n";
    else {
        for(auto c : result){
            cout << c << "\n";
        }
    }
    return 0;
}
