#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    queue <int> q;
    string order;
    int cnt = 0;
    int num = 0;
    cin >> cnt;

    for(int a = 0; a < cnt; a++){
        cin >> order;
        if(order == "push"){
            cin >> num;
            q.push(num);
        }
        else if(order == "front"){
            if(q.empty()) cout << -1 << "\n";
            else cout << q.front() << "\n";
        } 
        else if(order == "back"){
            if(q.empty()) cout << -1 << "\n";
            else cout << q.back() << "\n";
        } 
        else if(order == "size") cout << q.size() << "\n";
        else if(order == "empty") cout << q.empty() << "\n";
        else if(order == "pop"){
            if(q.empty()) cout << -1 << "\n";
            else{
             cout << q.front() << "\n";
             q.pop();
            }
        }
    }

    return 0;
}
