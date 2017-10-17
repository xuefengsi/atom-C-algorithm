#include<iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int *a = new int[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  int max,start;
  max=start=0;
  for(int i=0;i<n;i++)
  {
    start+=a[i];
    if(start>max)
      max = start;
    else if(start<0)
      start=0;
  }
  cout<<max<<endl;
}

