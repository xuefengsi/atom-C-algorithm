#include<iostream>
using namespace std;

void exchange(int a,int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int partition(int a[],int left,int right)
{
	int i=left-1;
	int x=a[right];
	int j;
	for(j=1;j<right;j++)
	{
		if(a[j]>x)
		{
			exchange(a[j],a[i+1]);
			i++;
		}
	}
	exchange(a[right],a[i+1]);
	return i+1;
}

int k_element(int a[],int left,int right,int k)
{
	if(left>=right)
		return a[left];
	int q=partition(a,left,right);
	if(q==k-1)
		return a[q];
	else if(q>=k)
		return k_element(a,left,q-1,k);
	else if(q<k)
		return k_element(a,q+1,right,k-(q+1));
}

int main()
{
	int a[100];
	int len;
	cin>>len;
	for(int i=0;i<len;i++)
		cin>>a[i]; 
	cout<<k_element(a,0,len-1,4)<<endl;
}
















