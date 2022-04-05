#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*bool dictionary(string str1, string str2,int cnt){
    if(str1[cnt] == str2[cnt]){
        return dictionary(str1,str2,cnt+1);
    }
    return str1[cnt] < str2[cnt];
}*/
bool compare(string str1, string str2){
    if(str1.size() == str2.size()){
        return str1 < str2;
        //dictionary함수를 사용하면 dictionary(str1,str2,0)를 넣어주면 됨 
    }
    return str1.size() < str2.size();
}
int main(void){
    vector<string> str;
    int Num = 0;
    string put_str = "";
    bool ask_put = true;
    cin >> Num;
    
    for(int a = 0; a < Num; a++){
        ask_put = true;
        cin >> put_str;
        for(int b = 0; b < str.size(); b++){
            if(put_str == str[b]) {
                ask_put = false;
                break;
            }
        }
        if(ask_put) str.push_back(put_str);       
    }
    sort(str.begin(),str.end(), compare);
    int c = 0;
   
    for(string a: str){
        cout << a << "\n";
    }
    return 0;
}
