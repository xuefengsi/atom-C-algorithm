#include<iostream>
using namespace std;
int main()
{
  int test;
  int n;
  while(cin>>n)
  {
    int a[n][2];
    for(int i=0;i<n;i++)
    {
      cin>>a[i][0]>>a[i][1];
    }
    int min = 0;
    for(int j=0;j<n;j++)
    {
      if(a[j][0]<a[min][0])
        min = j;
      else if(a[j][0] == a[min][0])
      {
        if(a[j][1] < a[min][1])
          min = j;
      }
    }
    cout<<a[min][0]<<" "<<a[min][1]<<endl;
  }
}
