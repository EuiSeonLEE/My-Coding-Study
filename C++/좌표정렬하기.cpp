#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair <int, int> XY1, pair <int, int> XY2){
    if(XY1.first == XY2.first){
        return XY1.second < XY2.second;
    }
    return XY1.first < XY2.first;
}

int main(void){
    vector<pair<int, int>> XY;
    int Num = 0;
    int x = 0, y = 0;
    cin >> Num;
    
    for(int a = 0; a < Num; a++){
        cin >> x >> y;
        XY.push_back(make_pair(x, y));
    }
    sort(XY.begin(), XY.end(), compare);
    
    for(auto a : XY){ //pair<int, int>대신 auto를 써도 된다.
        printf("%d %d\n",a.first,a.second); //cout은 느리다...
    }
    return 0;
}
