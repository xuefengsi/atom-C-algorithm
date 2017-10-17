#include<iostream>
#include<cstring>
#include<cstdio> 
void center(char a[],int n);
using namespace std;
int main()
{
	char a[100];
	gets(a);
	int len = strlen(a);
	center(a,len);
}

void center(char a[],int n)
{
	int i=0,j=n-1,flag=0;
	while(i<j)
	{
		if(a[i]!=a[j])
		{ 
			cout<<"false"<<endl;
			flag=1;
			break;
		}
		else
		{
			i++;
			j--;
		}
	}
	if(!flag)
		cout<<"true"<<endl;
}
