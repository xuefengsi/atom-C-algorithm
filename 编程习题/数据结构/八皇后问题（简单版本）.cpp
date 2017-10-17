/*
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
int n, tot, C[100];
void search(int cur)
{
	if (cur == n)
	{
		for (int i = 0; i < cur; i++)
			cout << C[i] << ",";
		cout << endl;
		tot++;
	}
	else
		for (int i = 0; i < n; i++)
		{
			int ok = 1;
			C[cur] = i;
			for(int j=0;j<cur;j++)
				if (C[cur] == C[j] || cur - C[cur] == j - C[j] || cur + C[cur] == j + C[j])
				{
					ok = 0;
					break;
				}
			if (ok)
				search(cur + 1);
		}
}
int main()
{
	tot = 0;
	cin >> n;
	memset(C, 0, sizeof(C));
	search(0);
	cout << tot << endl;
}
*/
/*
//n皇后问题 
#include<iostream> 
using namespace std;
void n_queen(int A[],int cur);
int n;
int num=0;
int main()
{
	cin>>n;
	int *A = new int[n];
	n_queen(A,0);
	cout<<num<<endl;
}


void n_queen(int A[],int cur)
{
	int j;
	if(cur==n)
	{
		for(j=0;j<n;j++)
		{
			cout<<A[j]<<" ";
		}
		num++;
		cout<<endl;
	}
	for(j=0;j<n;j++)
	{
		int flag=0,i;
		for(i=0;i<cur;i++)
		{
			if(j==A[i]||j-cur==A[i]-i||j+cur==A[i]+i)
			{
				flag=1;
				break;	
			}
		}
		if(!flag)
		{
			A[cur]=j;
			n_queen(A,cur+1);
		}
	}
}
*/
/*
//背包问题递归
#include<iostream> 
#include<cstring>
using namespace std;
int n;
int s;
int w[100];
int KNAP(int s,int n);
int main()
{
	cin>>n;
	memset(w,0,sizeof(n));
	for(int i=0;i<n;i++)
		cin>>w[i];
	cin>>s;
	KNAP(s,n);
}
int KNAP(int s,int n)
{
	if(s==0)
		return 1;
	if(s<0||s>0&&n<1)
		return 0;
	if(KNAP(s-w[n-1],n-1))//所选物品包括w[n]时 
		cout<<"物品:"<<n<<" "<<"重量:"<<w[n-1]<<endl; 
	else//所选物品不包括w[n]时 
		KNAP(s,n-1);
}
*/
/*
//递归输出1..n的全排列
#include<iostream>
using namespace std;
void perm(int A[],int m,int n);
int main()
{
	int n;
	cin>>n;
	int *A=new int[n];
	for(int i=0;i<n;i++)
		A[i]=i+1;
	perm(A,n-1,n);
	delete []A;
	
} 

void perm(int A[],int m,int n)
{
	int j,temp;
	if(m==0)
	{
		for(j=0;j<n;j++)
			cout<<A[j];
		cout<<endl;
	}
	else
	{
		for(j=0;j<=m;j++)
		{
			temp=A[m];A[m]=A[j];A[j]=temp;
			perm(A,m-1,n);
			temp=A[m];A[m]=A[j];A[j]=temp;
		}
	}
}
*/
/*
//求解最大公因数
#include<iostream> 
using namespace std;
int GCD(int m,int n);
int main()
{
	int m,n;
	cin>>m>>n;
	cout<<GCD(m,n)<<endl;;
}
int GCD(int m,int n)
{
	if(m<0)
		m=-m;
	if(n<0)
		n=-n;
	if(m<n)
		return GCD(n,m);
	if(n==0)
		return m;
	return GCD(n,m%n);
}
*/








































