#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    vector<int> arr;
    int Num = 0;
    int arrNum = 0;
    cin >> Num;
    
    for(int a = 0; a < Num; a++){
        cin >> arrNum;
        arr.push_back(arrNum);
    }
    
    sort(arr.begin(),arr.end()); //(퀵정렬+삽입정렬)기반 정렬
    
    for(int b = arr.size() - 1; b >= 0; b--){
        cout << arr[b] << endl;
    }
    return 0;
}