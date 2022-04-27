#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <numeric>

using namespace std;


int main(void){
    char num[4] = "123";
    int result;
    string chage = num;
    result = stoi(chage);

    cout << result<<endl;

    return 0;
}
