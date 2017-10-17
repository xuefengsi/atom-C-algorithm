
#include<iostream>
using namespace std;
void maxLenPlat(int a[],int n);
int main()
{
	int a[5]={1,2,2,2,3};
	maxLenPlat(a,5);
}

void maxLenPlat(int a[],int n)
{
	int i=0,k,t=0;
	int start=0,len=0;
	while(i<n)
	{
		k=1;
		i++;
		while(i<n&&a[i]==a[i-1])
		{
			k++;
			i++;
		}
		if(k>len)
		{
			len=k;
			start=t;
		}
		t=i;
	}
	cout<<len
	<<endl;
	cout<<start<<endl;
}
