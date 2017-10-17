#include<iostream>
#include<cstring>
using namespace std;
int Min(int *a,int &n)
{
  int i,k=0,min;
  min = a[0];
  for(i=1;i<n;i++)
  {
    if(a[i]<min)
    {
      min = a[i];
      k = i;
    }
  }
  a[k] = a[--n];
  return min;
}
int main()
{
  int n;
  while(cin>>n)
  {
      int b[1000],i;
      for(i=0;i<n;i++)
        cin>>b[i];
      int sum=0,wgt=0;
      while(n>1)
      {
        sum = Min(b,n) + Min(b,n);
        wgt+=sum;
        b[n++] = sum;
      }
      cout<<wgt<<endl;
  }
}
