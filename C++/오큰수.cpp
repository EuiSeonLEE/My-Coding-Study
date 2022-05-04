#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <numeric>

using namespace std;

/*배열의 요소가 0~n번째 요소가 있다면
오큰수는 배열의 i+n번째 요소가 
i번째 요소보다 큰 수 中,
가장 왼쪽의 수(Minimum(n))이다.*/
//오큰수(i) = 배열의 i + Minimum(n)

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int array_cnt = 0,array_num = 0;
    
    vector<int> array, result;
    stack<int> stk;
    cin >> array_cnt;
    for(int a = 0; a < array_cnt; a++){
        cin >> array_num;
        array.push_back(array_num);
    }//만약 {9,5,4,8,10,7,6,2} 라면
    
    for(int a = array_cnt - 1; a >= 0; a--){ //수열을 reverse 방향으로 
        while(!stk.empty()&&stk.top() <= array[a]) stk.pop();
        if(stk.empty()) result.push_back(-1);
        else result.push_back(stk.top());
        stk.push(array[a]);        
    }
    for(int a = array_cnt - 1; a >= 0; a--) cout << result[a] << " ";
    
    
    return 0;
}
