
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//계수정렬(counting sort)
int main(void){
    vector<int> arr(10001);
    int Num = 0;
    int arrNum = 0;
    scanf("%d",&Num);
    
    for(int a = 0; a < Num; a++){
        scanf("%d",&arrNum);
        arr[arrNum]++;
    }
 
    for(int b = 0; b < arr.size(); b++){
        if(arr[b] != 0){
            for(int c = 0; c < arr[b]; c++){
                printf("%d\n",b);
            }
        }
    }
    return 0;
}