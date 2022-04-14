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
    vector<string> yesorno;
    stack<string> stk;
    int num = 0;
    string put_wall = "";

    cin >> num;

    for(int a = 0; a < num; a++){
        cin >> put_wall;
        for(int b = 0; b < put_wall.size(); b++){
            stk.push(put_wall.substr(b,1));
            if(stk.size() > 1){
                stk.pop();
                if(put_wall.substr(b,1) == ")" && stk.top() == "(") {
                    stk.pop();
                }
                else stk.push(put_wall.substr(b,1));
            }
        }
        if(stk.empty()) yesorno.push_back("YES");
        else yesorno.push_back("NO");
        while(!stk.empty()) stk.pop();
    }
    for(auto c : yesorno) cout << c <<"\n";

    return 0;
}
