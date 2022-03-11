#include <iostream>
using namespace std;

int main(void)
{
  int Cnt = 0,Sum = 0;
  int Num[] = {0,};

  cin >> Cnt;
  for (int a = 0; a < Cnt; a++){
    cin >> Num[a];
    Sum += Num[a];
  }
  cout << "숫자의 합 = " << Sum << endl;
  return 0;
}
