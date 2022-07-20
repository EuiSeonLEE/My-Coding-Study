#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <numeric>

using namespace std;
//1. isdigit함수는 문자열의 숫자를 판단하는 함수이다.(중요)
//2. split은 왜 안돼는걸까???
/*deque<int> split(string &input, string delimiter){
	deque<int> ret;
	long long pos = 0;
	string token = "";
	while ((pos = input.find(delimiter)) != string::npos){
		token = input.substr(0, pos);
		ret.push_back(stoi(token));
		input.erase(0, pos + delimiter.length());
	}
	ret.push_back(stoi(input));
	return ret;
}*/
void print_dq(deque <int> &dq, bool &R){            
    if(R == false){
        for(int x = 0; x < dq.size() - 1; x++){
            cout << dq[x]<< ",";
        }
        cout << dq[dq.size() - 1];
    }
    else {
        for(int x = dq.size() - 1; x > 0; x--){
            cout << dq[x]<< ",";
        }
        cout << dq[0];

    }
}
void Order(deque <int> &dq, bool &R){
    if(R == false) dq.pop_front();
    else dq.pop_back();
    
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    deque <int> dq;
    int Cnt = 0, Num = 0;
    string order = "", realnum = "", s = "";
    bool R = false, error = false;

    cin >> Cnt;
    for(int a = 0; a < Cnt; a++){
        dq.clear();
        error = false;
        R = false;
        cin >> order;
        cin >> Num;
        cin >> realnum;

       /* realnum = realnum.substr(1, realnum.find(']'));
        if(!realnum.empty()) dq = split(realnum, ",");*/
        for (int i = 0; i<realnum.length();i++) {
            if (isdigit(realnum[i])) { // 숫자 판단
                s += realnum[i];

            }
            else {
                if (!s.empty()) {
                    dq.push_back(stoi(s));
                    s = "";
                }
            }
        }
       /* for(auto a : dq) cout << a <<":";
        cout << "\n";*/

        for(int d = 0; d < order.size(); d++){
            if(order[d] == 'R') {
                if(R) R = false;
                else R = true;
            }
            else if(order[d] == 'D'){
                if(dq.empty()) {
                    cout << "error\n"; 
                    error = true;
                    break;
                }
                Order(dq, R);
            }
        }
        
          if(error == false) {
            cout << "[";
            if(!dq.empty()) print_dq(dq, R);
            cout << "]\n";
          }
        
    }

    return 0;
}
