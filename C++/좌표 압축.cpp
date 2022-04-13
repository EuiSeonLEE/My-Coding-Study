#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> Coordinates;
    vector<int> UniqueSort;

    int Num = 0;
    int put_Coordinates= 0;
    bool ask_put = true;
    cin >> Num;
    
    for(int a = 0; a < Num; a++){
        ask_put = true;
        cin >> put_Coordinates;
        Coordinates.push_back(put_Coordinates);
        UniqueSort.push_back(put_Coordinates);
        
    }
    sort(UniqueSort.begin(),UniqueSort.end());
    //unique()함수는 중복되는 요소(숫자,문자열 등)들을 배열 맨뒤로 보내버린다.
    //return되는 건 (배열크기 - 중복요소갯수)이다.
    UniqueSort.erase(unique(UniqueSort.begin(),UniqueSort.end()),UniqueSort.end());
    for(int a = 0; a < Coordinates.size(); a++){
        auto point = lower_bound(UniqueSort.begin(), UniqueSort.end(), Coordinates[a]);
        cout << point - UniqueSort.begin() << " ";
    }
   
    return 0;
}
