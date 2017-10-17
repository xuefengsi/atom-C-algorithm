#include<iostream>
using namespace std;
int main()
{
  int n;
  while(cin>>n)
  {
    int i,a[1000];
    for(i=0;i<n;i++)
      cin>>a[i];
    int count1,count2;
    count1=count2=0;
    for(i=0;i<n;i++)
    {
      if(a[i]%2==0)
        count1++;
      else
        count2++;
    }
    if(count1>count2)
      cout<<"NO"<<endl;
    else
      cout<<"YES"<<endl;
  }
}
