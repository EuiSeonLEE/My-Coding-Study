#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(pair<int, string> member1, pair<int, string> member2){
    return member1.first < member2.first;
}

int main(void){
    vector<int> Coordinates;
    vector<int> Coordinates_sort;
    int Num = 0;
    int put_Coordinates= 0;
    bool ask_put = true;
    cin >> Num;
    
    for(int a = 0; a < Num; a++){
        ask_put = true;
        cin >> put_Coordinates;
        Coordinates.push_back(put_Coordinates);
        for(int b = 0; b < Coordinates.size();b++){
            if(put_Coordinates == Coordinates[b]){
                ask_put = false;
                break;
            }
        }
        if(ask_put) Coordinates_sort.push_back(put_Coordinates);
    }
    sort(Coordinates_sort.begin(),Coordinates_sort.end());

    for(int a = 0; a < Coordinates.size(); a++){
        
    }
    return 0;
}
