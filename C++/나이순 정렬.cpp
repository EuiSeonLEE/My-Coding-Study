#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(pair<int, string> member1, pair<int, string> member2){
    return member1.first < member2.first;
}

int main(void){
    vector<pair<int,string>> member;
    int Num = 0;
    int put_age = 0;
    string put_name = "";
    bool ask_put = true;
    cin >> Num;
    
    for(int a = 0; a < Num; a++){
        cin >> put_age >> put_name;
        member.push_back(make_pair(put_age, put_name));
    }
    stable_sort(member.begin(),member.end(), compare);

    for(auto a: member){
        cout << a.first << " "<< a.second<<"\n";
    }
    return 0;
}
