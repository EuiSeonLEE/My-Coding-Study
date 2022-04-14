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

    stack<char> stk;
    string put_wall = "";

    while(1){
        getline(cin, put_wall);
        if(put_wall[0] == '.') break;
        for(int b = 0; b < put_wall.size(); b++){
            if(put_wall[b] == '(' || put_wall[b] == '[' ||put_wall[b] == ')' ||put_wall[b] == ']'){            
                stk.push(put_wall[b]);
                if(stk.size() > 1){
                   stk.pop();
                    if(put_wall.substr(b,1) == ")" && stk.top() == '(') {
                        stk.pop();
                    }
                    else if(put_wall.substr(b,1) == "]" && stk.top() == '[') {
                        stk.pop();
                    }
                    else stk.push(put_wall[b]);
                }
            } 
        }
        if(stk.empty()) cout <<"yes\n"; 
        else cout <<"no\n";
        while(!stk.empty()) stk.pop();
    }
    return 0;
}
