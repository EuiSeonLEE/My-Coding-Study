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
    int N = 0, cnt = 0;

    cin >> N;
    for(int a = 1; a <= N; a++) q.push(a);
    while(q.size() > 1){
        cnt++;
        if(cnt%2 == 1) q.pop();
        else {
            q.push(q.front());
            q.pop();
        }
    }
    cout << q.front() <<"\n";

    return 0;
}
