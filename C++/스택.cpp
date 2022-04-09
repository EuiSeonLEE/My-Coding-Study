#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<int> stk;
    int num = 0;
    string order = "";

    cin >> num;

    for(int a = 0; a < num; a++){
        cin >> order;
        if(order == "push"){
            int sdk_push = 0;
            cin >> sdk_push;
            stk.push(sdk_push);
        }
        else if(order == "pop"){
            if(stk.empty()) cout << "-1\n";
            else {
                cout << stk.top() << "\n";
                stk.pop();
            }
        }
        else if(order == "size"){
            cout << stk.size() << "\n";
        }
        else if(order == "empty"){
            cout << stk.empty() << "\n";
        }
        else if(order == "top"){
            if(stk.empty()) cout << "-1\n";
            else cout << stk.top() << "\n";
            
        }
    }
    
    return 0;
}
