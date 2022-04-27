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
    stack<int> stk_sub;
    stack<char> result;
    int cnt = 0;
    int num = 0;
    string put_wall = "";
    bool Not = true;
    //중간고사 끝나고 코딩연습 다시 재개할 것....
    //오미크론 7일 째

    cin >> cnt;
    for(int a = 0; a < cnt; a++){
        cin >> num;
        array.push_back(num);
    }//{4,3,6,8,7,5,2,1} 
    
    for(int b = array.size() - 1; b >= 0; b--){
        if(!stk.empty()){
            if(array[b] < stk.top()){
                stk_sub.push(stk.top());
                stk.pop();
                result.push('+');
                b++;
            }
            else {
                stk.push(array[b]);
                result.push('-');
      
            }
        }
        else {
            if(Not){
                stk.push(array[b]);
                result.push('-');
                Not = false;
            }
            else{
                cout << "NO";
                return 0;
            }
      
        }
    }
    if(!stk_sub.empty()){
        while(!stk_sub.empty()){
            stk.push(stk_sub.top());
            stk_sub.pop();
            result.push('+');

        }
    }
    if(!result.empty()){
        while(!result.empty()){
            cout << result.top() << "\n";
            result.pop();
        }
    }
    return 0;
}
