#include<iostream>
using namespace std;

int main()
{
  int n,result[1000][50],k=0,num[1000];
  cin>>n;
  while(n--)
  {
    int m;
    cin>>m;
    int l=0;
    while(m!=0)
    {
      result[k][l++] = m%2;
      m = m/2;
    }
    num[k] = l;
    k++;
  }
  for(int i=0;i<k;i++)
  {
    for(int j=num[i]-1;j>=0;j--)
    {
      cout<<result[i][j];
    }
    cout<<endl;
  }
}
