#include <iostream>
using namespace std;

int main(void)
{
  char major[100];
  cout<<"stay:";
  cin>>major;

  int studentnum;
  cout<<"학번을 입력하세요:";
  cin>>studentnum;

  char student[100];

  cout<<"이름을 입력하세요:";

  cin>>student;

  char project[100];
  cout<<"제목을 입력하세요:";
  cin>>project;

  cout<<"학과:"<<major<<endl<<"학번:"<<studentnum<<endl<<
  "이름:"<<student<<endl<<endl<<"제목:"<<project<<endl<<endl;

  cout<<"수를 입력하세요:";

  int num;
  cin >> num;

  cout << "입력된 정수는" <<num << "입니다"<<endl;

  return 0;
}
