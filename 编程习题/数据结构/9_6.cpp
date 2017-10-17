//将数组A中的所有非0元素移到前面
/* 
#include<iostream>
using namespace std;
void compact(int A[],int n);
int main()
{
	int n;
	cin>>n;
	int *A=new int[n];
	for(int i=0;i<n;i++)
		cin>>A[i];
	compact(A,n);
	delete []A;
}
void compact(int A[],int n)
{
	int f=0;
	for(int i=0;i<n;i++)
	{
		if(A[i]!=0)
		{
			if(i!=f)
			{
				A[f]=A[i];
				A[i]=0;
			}
			f++;
		}
	}
	for(int i=0;i<n;i++)
		cout<<A[i]<<" ";
	cout<<endl;
}
*/

#include<iostream>
using namespace std;
void deleteSame(int A[],int n);
int main()
{
	int n;
	cin>>n;
	int *A=new int[n];
	for(int i=0;i<n;i++)
		cin>>A[i];
	deleteSame(A,n);
	delete []A;
}

void deleteSame(int A[],int n)
{
	int f=1;
	for(int i=1;i<n;i++)
	{
		if(A[i]!=A[i-1])
		{
			if(i!=f)
				A[f]=A[i];
			f++;
		}
	}
	for(int i=0;i<f;i++)
		cout<<A[i]<<" ";
	cout<<endl; 
}
