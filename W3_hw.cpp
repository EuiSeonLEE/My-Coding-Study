#include <iostream>
using namespace std;

int main(void)
{
  char major[100];
  cout<<"stay:";
  cin>>major;

  int studentnum;
  cout<<"�й��� �Է��ϼ���:";
  cin>>studentnum;

  char student[100];

  cout<<"�̸��� �Է��ϼ���:";

  cin>>student;

  char project[100];
  cout<<"������ �Է��ϼ���:";
  cin>>project;

  cout<<"�а�:"<<major<<endl<<"�й�:"<<studentnum<<endl<<
  "�̸�:"<<student<<endl<<endl<<"����:"<<project<<endl<<endl;

  cout<<"���� �Է��ϼ���:";

  int num;
  cin >> num;

  cout << "�Էµ� ������" <<num << "�Դϴ�"<<endl;

  return 0;
}