#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <numeric>

using namespace std;


int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int X = 0, Y = 0;
    for(int i = 0; i < sizes.size(); i++){
       if(sizes[i][0] < sizes[i][1]){
            swap(sizes[i][0], sizes[i][1]);
       }
       if(X < sizes[i][0]){
            X = sizes[i][0];
       }
       if(Y < sizes[i][1]){
            Y = sizes[i][1];
       }
    }
    answer = X * Y;
    
    return answer;
}
