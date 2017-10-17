/*
#include<iostream>
using namespace std;
int Binary_search(int a[],int n,int value,bool IsLeft)
{
  int left = 0;
  int right = n-1;
  int last;
  while(left<=right)
  {
    int mid = (left+right)/2;
    if(a[mid] > value)
      right = mid - 1;
    else if(a[mid] < value)
      left = mid + 1;
    else
    {
      last = mid;
      if(IsLeft)
        right = mid - 1;
      else
        left = mid + 1;
    }
  }
  return last;
}

int main()
{
  int n;
  cin>>n;
  int *a = new int[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  int value;
  cin>>value;
  int left = Binary_search(a,n,value,true);
  int right = Binary_search(a,n,value,false);
  int count = right - left + 1;
  cout<<count<<endl;
  delete []a;
}
*/

#include<iostream>
using namespace std;
int Binary_search(int a[],int n,int value,bool IsLeft)
{
  int left = 0;
  int right = n - 1;
  int last;
  while(left<=right)
  {
    int mid = (left+right)/2;
    if(a[mid] > value)
      right = mid - 1;
    else if(a[mid] < value)
      left = mid + 1;
    else
    {
      last = mid;
      if(IsLeft)
        right = mid -1;
      else
        left = mid +1;
    }
  }
  return last;
}
int main()
{
  int a[5] = {1,2,2,3,4};
  int left = Binary_search(a,5,2,true);
  int right = Binary_search(a,5,2,false);
  int count = right - left + 1;
  cout<<count<<endl;
}
