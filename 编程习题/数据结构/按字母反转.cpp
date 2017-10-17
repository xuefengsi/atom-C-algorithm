
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char a[100];
	gets(a);
	for(int i=strlen(a)-1;i>=0;i--)
	{
		if(a[i]==' ')
		{
			for(int j=i+1;j<strlen(a);j++)
			{
				if(a[j]==' ')
					break;
				else
					cout<<a[j];
			}
			cout<<" ";
		}
		else if(i==0)
		{
			for(int j=i;;j++)
			{
				if(a[j]==' ')
					break;
				else
					cout<<a[j];
			}
			cout<<" ";
		}
	}
	cout<<endl;
} 
