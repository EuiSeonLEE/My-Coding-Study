#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <numeric>

using namespace std;
//lower_bound를 쓰면 안되는 이유는?
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    deque <int> dq;
    int N = 0, M = 0, Num = 0, Cnt = 0, point = 0;

    cin >> N >> M;
    for(int a = 1; a <= N; a++) dq.push_back(a);

    //회전하고 pop하고 cnt올리는 구조
    //입력된 M의 갯수만큼의 채택 숫자를 전부 해결할 때까지
    while(1){
        cin >> Num;
        for (int i = 0; i < dq.size(); ++i) {
			if (dq[i] == Num) {
				point = i;
				break;
			}
		}
        
        //point = (int)(lower_bound(dq.begin(), dq.end(), Num) - dq.begin());
           // cout << point << " : " << dq.size() << "\n";
            if(point >= (dq.size() - point)) {
                //왼
                while(1){
                    if(dq.front() == Num){
                        dq.pop_front(); 
                        break;
                    }
                    ++Cnt; 
                    dq.push_front(dq.back());
                    dq.pop_back();
                }
            }
            else {
                //오
                while(1){
                    if(dq.front() == Num){
                        dq.pop_front(); 
                        break;
                    } 
                    ++Cnt;
                    dq.push_back(dq.front());
                    dq.pop_front();
                }
            }
        M--; //if M =3 이면 2 1 0
        if(M == 0) break;
    }
    cout << Cnt << "\n";

    return 0;
}
