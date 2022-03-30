#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
/*통계학
1. 산술평균 : N개의 수들의 합을 N으로 나눈 값
2. 중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
3. 최빈값 : N개의 수들 중 가장 많이 나타나는 값
4. 범위 : N개의 수들 중 최댓값과 최솟값의 차이
*/
int main(void){
    vector<int> Arr, value;
    int Num = 0;
    int arrNum = 0;
    float AvrNum = 0.0;
    int CntMaxNum = 0;
    int CntMax = 0;
    int CntMax_before = 0;
    
    while(1){
        scanf("%d",&Num);
        if(Num%2 == 1) break;
    }
    for(int a = 0; a < Num; a++){
        scanf("%d",&arrNum);
        Arr.push_back(arrNum);
    }
    sort(Arr.begin(), Arr.end());
    CntMaxNum = Arr[0];
    int Sum = 0;
    int Cnt = 0;
    for(int b = 0; b < Arr.size(); b++){
        Sum += Arr[b];
        
        if(Arr[b] == Arr[b - 1]) CntMax_before ++;
        else CntMax_before = 0;

        if(CntMax_before >= CntMax){
            if(CntMax_before == CntMax){
                Cnt ++;
                if(CntMax == 0 && Cnt == 2) CntMaxNum = Arr[b];
                else if(Cnt == 1) CntMaxNum = Arr[b];
            }
            else {
                CntMax = CntMax_before;
                CntMaxNum = Arr[b];
                Cnt = 0;
            }
        }
    }
    AvrNum = round(((float)Sum / (float)Arr.size()));

    printf("%d\n",(int)AvrNum);
    printf("%d\n", Arr[(Arr.size()) / 2]);
    printf("%d\n", CntMaxNum);
    printf("%d\n", Arr[Arr.size() - 1] - Arr[0]);
    return 0;
}