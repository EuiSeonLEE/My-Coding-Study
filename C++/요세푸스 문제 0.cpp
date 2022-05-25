#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    queue <int> q;
    vector <int> v;
    int N = 0, K = 0, cnt = 0;

    cin >> N;
    cin >> K;
    for(int a = 1; a <= N; a++) q.push(a);
        if(K == 1){
            while(q.size() > 0){
                v.push_back(q.front());
                q.pop();
            }
        }
        else {
            while(q.size() > 0){
                cnt++;
                if(cnt%K == 0){
                    v.push_back(q.front());
                    q.pop();
                    cnt++;
                }
                q.push(q.front());
                q.pop();
            }
    }
    cout << "<" << v[0];
    for(int a = 1; a < v.size(); a++) cout <<  ", " << v[a];
    cout << ">";
    
    return 0;
}
