/*
#include<iostream>
using namespace std;
int getRlt(long long n,long long m);
int main()
{
	long long m,n;
	while(cin>>m>>n)
	{
		if(m==0&&n==0)
		{
			break;
		}
		else
		{
			cout<<getRlt(n,m)<<endl;
		}
	}
} 

int getRlt(long long n,long long m)
{
	int s=1,i=1;
	while(n>=2*m)
	{
		if(n==2*m)
		{
			s += 1;
			m = 2*m;
		}
		else
		{
			s += 2*i;
			i++;
			m = 2*m;
		} 
	}
	return s;
}

*/
/*
//n皇后问题的所有可行解，递归。 
#include<iostream>
#include<stdlib.h>
#define maxn 100
using namespace std;
int n=8;
int count=0;
int A[maxn];
int num[maxn][maxn];
void sort(int cur);
int main()
{
	int *A,m,k;
	cin>>k;
	sort(1);
	for(int i=0;i<k;i++)
	{
		cin>>m;
		for(int j=1;j<=n;j++)
			cout<<num[m][j];
		cout<<endl;
		
	}
	
}

void sort(int cur)
{
	if(cur==n+1)
	{
		count += 1;
		for(int i=1;i<=n;i++)
			num[count][i]=A[i];
		
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			int flag=1;
			A[cur]=i;
			for(int j=1;j<cur;j++)
			{
				if(A[cur]==A[j]||cur-A[cur]==j-A[j]||cur+A[cur]==j+A[j])
				{
					flag=0;
					break;
				}
			}
			if(flag)
				sort(cur+1);
		}
	}
}
*/
/*
//鸡兔同笼 
#include<iostream>
#define maxn 100
using namespace std;
void CalNum(int m);
int result[2];
int k=0;
int main()
{
	int n,m,v;
	cin>>n;
	v=n;
	while(n>0)
	{
		cin>>m;
		CalNum(m);
		cout<<result[0]<<" "<<result[1]<<endl;
		n--;
	}
	/*
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<2;j++)
		{
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
}

void CalNum(int m)
{
	if(m%2==0)
	{
		result[0] = m/4 + (m%4==0?0:1);
		result[1] = m/2;
	}
	else
	{
		result[0]=result[1]=0;
	}
	//k++;
}
*/
/*
//加减乘除运算 
#include<iostream>
#include<cstring>
using namespace std;
int JC(int m);
int main()
{
	int m,n;
	char s;
	while(cin>>m)
	{
		cin>>s;
		if(s!='!')
		{
			cin>>n;
			if(s=='+')
				cout<<m+n<<endl;
			else if(s=='-')
				cout<<m-n<<endl;
			else if(s=='*')
				cout<<m*n<<endl;
			else if(s=='/')
			{
				if(n==0)
					cout<<"error"<<endl;
				else
					cout<<m/n<<endl;
			}
			else if(s=='%')
			{
				if(n==0)
					cout<<"error"<<endl;
				else
					cout<<m%n<<endl;
			}
			
		}
		else
			cout<<JC(m)<<endl;
	}

} 
int JC(int m)
{
	if(m<=1)
		return 1;
	else
		return m*JC(m-1);
}
*/



















































































