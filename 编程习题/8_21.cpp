#include<iostream>
using namespace std;
int main()
{
	int n,i,x[100],y[100],l=0,k=0,sum=0,m=0,j;
	float fk[100];
	cin>>n;
	for(i=0;i<n;i++)
	{
		if((i+2)%2==0)
		{
			cin>>x[k];
			k +=1; 
		} 
		else
		{
			cin>>y[l];
			l += 1;
		}
	}
	cout<<l;
	for(j=1;j<l;j++)
	{
			fk[m] = (y[0]-y[j])/(x[0]-x[j]);
			m +=1;
			cout<<fk[j];
	}
	for(i=0;i<m;i++)
	{
		if(fk[i]==fk[0])
		{
			sum += 1;
		}
	}
	cout<<sum<<endl;
} 
