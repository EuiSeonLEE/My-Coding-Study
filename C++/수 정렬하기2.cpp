#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main(void){
    vector<int> arr, arr2;
    int Num = 0;
    int arrNum = 0;
    cin >> Num;
    
    for(int a = 0; a < Num; a++){
        cin >> arrNum;
        arr.push_back(arrNum);
        push_heap(arr.begin(),arr.end());
    }
    //make_heap(arr.begin(),arr.end());
    sort_heap(arr.begin(),arr.end());
    //sort(arr.begin(),arr.begin()+(Num/2));
    //sort(arr.begin()+(Num/2),arr.end());
    //inplace_merge(arr.begin(),arr.begin()+(Num/2),arr.end());
 
    for(int b = 0; b < arr.size(); b++){
        cout << arr[b] << '\n'; //endl은 flush을 사용하기 때문에 느리다...
    }
    return 0;
}