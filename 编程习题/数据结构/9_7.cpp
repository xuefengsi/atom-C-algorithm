#include<iostream>
using namespace std;
int main()
{
	float a[12],b[12],sum=0;
	int i;
	for(i=0;i<12;i++)
		cin>>a[i];
	for(i=0;i<12;i++)
		cin>>b[i];
	for(i=0;i<12;i++)
		sum += a[i]*b[i]/33.5;
	cout<<sum;
	
}
