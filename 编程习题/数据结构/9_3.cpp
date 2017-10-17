//三元组
/* 
#include<iostream>
#include<stdlib.h>
void* malloc(size_t size);
using namespace std;
int main()
{
	int test,n,m,*result,*A,g=0,j,k,i;
	cin>>test;
	result=(int*)malloc(sizeof(int)*test);
	while(test>0)
	{
		int num=0;
		cin>>m;
		A=(int*)malloc(sizeof(int)*m);
		for(i=0;i<m;i++)
		{
			cin>>A[i];
		}
		for(i=0;i<m;i++)
		{
			for(j=0;j<m;j++)
			{
				for(k=0;k<m;k++)
				{
					if(A[i]+A[j]==A[k])
						num++;
				}
			}
		}
		result[g]=num;
		g++;
		test--;
	}
	for(i=0;i<g;i++)
		cout<<result[i]<<endl;
} 
*/
//寻找变化前01序列
/*
#include<iostream>
#include<cstring>
#define maxn 100
using namespace std;
char s[maxn];
char result[maxn][maxn];
int Tolen[maxn];
int main()
{
	int test,i,k=0,h=0;
	cin>>test;
	while(test>0)
	{
		cin>>s;
		int num=0,j=0;
		int len=strlen(s);
		for(i=0;i<len;i++)
		{
			if(s[i]=='1')
			{
				result[k][j]=s[i];
				j++;
				num++;
				if(num==5)
				{
					i++;
					num=0;
				}
			}
			else
			{
				result[k][j]=s[i];
				j++;
				num=0;
			}
		}
		Tolen[h]=j;
		h++;
		k++;
		test--;
	}
	for(i=0;i<k;i++)
	{
		for(k=0;k<Tolen[i];k++)
		{
		 	cout<<result[i][k];	
		}
		cout<<endl;
	}
} 
*/


//寻找i*j=m的个数
/*
#include<iostream> 
#define maxn 100
int result[maxn];
using namespace std;
int main()
{
	int test,m,n,i,k=0;
	cin>>test;
	while(test>0)
	{
		cin>>n>>m;
		int num=0;
		for(i=1;i<=n;i++)
		{
			if(m%i==0&&(m/i)<=n)
				num++;
		}
		result[k]=num;
		k++;
		test--;
	}
	for(i=0;i<k;i++)
		cout<<result[i]<<endl; 
}
*/










































