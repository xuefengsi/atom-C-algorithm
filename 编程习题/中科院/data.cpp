#include<iostream>
#include<fstream>
using namespace std;
int main()
{
  ofstream in;
  in.open("data.txt",ios::trunc);
  int num=1;
  for(int i=1;i<=128*128*128*2;i++)
  {
    int value = rand()%(0,1000);
    if(i%2==0)
    {
      if(i<128*128*128*2)
        in<<value<<"\n";
      else
        in<<value;
    }
    else
    {
      in<<num<<" "<<value<<" ";
      num++;
    }
  }
  in.close();
}
