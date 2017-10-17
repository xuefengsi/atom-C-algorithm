#include<iostream>
#include<cmath>
using namespace std;
int main()
{
  int n;
  while(cin>>n)
  {
    int i;
    int *a = new int[n];
    for(i=0;i<n;i++)
      cin>>a[i];
    int h;
    cin>>h;
    //cout<<int(log(n)/log(2))<<endl;
    if(h>int(log(n)/log(2))+1)
      cout<<"error"<<endl;
    else if(pow(2,h)-1>=n)
    {
      for(i=pow(2,h-1);i<=n;i++)
        cout<<i<<" ";
      cout<<endl;
    }
    else

    {
      for(i=pow(2,h-1);i<=pow(2,h-1)+pow(2,h-1)-1;i++)
        cout<<i<<" ";
      cout<<endl;
    }
  }
}
