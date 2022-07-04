#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
//ㅇ
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	deque<int> dq;
    int cnt = 0, n = 0;
    string order;

    cin >> cnt;
    for(int a = 0; a < cnt; a++){
        cin >> order;
        if(order == "push_back"){
            cin >> n;
            dq.push_back(n);
        }
        else if(order == "push_front"){
            cin >> n;
            dq.push_front(n);
        }
        else if(order == "front"){
            if(dq.empty()) cout << -1 << "\n";
            else cout << dq.front() << "\n";
        }
        else if(order == "back"){
            if(dq.empty()) cout << -1 << "\n";
            else cout << dq.back() << "\n";
        }
        else if(order == "size"){
            cout << dq.size() << "\n";
        }
        else if(order == "empty"){
            cout << dq.empty() << "\n";
        }
        else if(order == "pop_front"){
            if(dq.empty()) cout << -1 << "\n";
            else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        else if(order == "pop_back"){
            if(dq.empty()) cout << -1 << "\n";
            else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
    }
	
	return 0;
}
