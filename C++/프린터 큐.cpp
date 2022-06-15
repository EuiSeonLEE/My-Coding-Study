#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
//기말 준비중17
//우선순위 큐를 사용해야함
//
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    queue <int> q, q_ipt;
    vector <int> v;
    vector <pair<int,int>> num_cnt;
    vector <pair<int,int>> v_ipt;
    int num = 0, cnt = 0;
    int N = 0, K = 0, ipt = 0;

    cin >> N;
    for(int a = 0; a < N; a++){
        cin >> num >> cnt;
        num_cnt.push_back(make_pair(num, cnt));
        for(int b = 0; b < num_cnt[a].first; b++){
            cin >> ipt;
            q.push(b);
            if(q_ipt.front() < ipt){
                while(q_ipt.front() < ipt){
                    q_ipt.push(q_ipt.front());
                    q.push(q.front());
                    q_ipt.pop();
                    q.pop();
                }    
            }            
        }
        int K = 0;
        while(q.front() != num_cnt[a].second){
            q_ipt.pop();
            q.pop();
            K++;
        }
        v.push_back(K+1);
        while(!q.empty()) q.pop(); q_ipt.pop();
    }
    for(auto x : v) cout << x << "\n";

    return 0;
}

