#include<iostream>
using namespace std;
void reverse(int *a,int n);
int main()
{
	int n=123456;
	int a[6];
	reverse(a,n);
	for(int i=0;i<6;i++)
		cout<<a[i];
}
void reverse(int *a,int n)
{
	if(n>0)
	{
		*a=n%10;
		
		reverse(a+1,n/10);
	} 
}
