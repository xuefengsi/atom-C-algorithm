#include<iostream>
using namespace std;
int Binary_search(int a[],int n,int value)
{
  int left = 0;
  int right = n-1;
  while(left<=right)
  {
    int mid = (left+right)/2;
    if(a[mid]==value)
      return 1;
    else if(a[mid]>value)
      right = mid-1;
    else
      left = mid+1;
  }
  return 0;
}
int main()
{
  int n;
  while(cin>>n)
  {
    int *a = new int[n];
    for(int i=0;i<n;i++)
      cin>>a[i];
    int m;
    cin>>m;
    int *b = new int[m];
    for(int i=0;i<m;i++)
    {
      cin>>b[i];
    }
    for(int i=0;i<m;i++)
    {
      int flag = Binary_search(a,n,b[i]);
      if(flag)
        cout<<"YES"<<endl;
      else
        cout<<"NO"<<endl;
    }
    delete []a;
    delete []b;
  }
}
