/*
#include<iostream>
#include<stdlib.h>
void* malloc(size_t size);
using namespace std;
int DeqSearch(int A[],int value,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(A[i] == value)
		{
			return i;
		}
	}
	return -1;
}
int BinarySearch1(int A[],int value,int n)
{
	int low,high;
	low = 0;
	high = n - 1;
	while(low<=high)
	{
		int mid = (low+high)/2;
		if(A[mid] == value)
		{
			return mid;
		}
		if(A[mid] < value)
		{
			low = mid + 1;
		}
		if(A[mid] > value)
		{
			high = mid - 1;
		}
	}
	return -1;
	
}
int BinarySearch2(int A[],int value,int left,int right)
{
	int mid;
	mid = left + (right-left)/2;
	if(left<=right)
	{
		if(A[mid]==value)
		{
			return mid;
		}
		if(A[mid] >value)
		{
			BinarySearch2(A,value,left,mid-1);
		}
		if(A[mid] < value)
		{
			BinarySearch2(A,value,mid+1,right);
		}
	}
	return -1;
}
int main()
{
	int n,*A;
	cin>>n;
	A = (int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	int value;
	cin>>value;
	cout<<BinarySearch2(A,value,0,n-1);
} 
*/

#include<iostream>
#include<stdlib.h>
#define maxn 100
void* malloc(size_t size);
int result[maxn]={-1};
int k=1;
using namespace std;
struct node
{
	node *lchild;
	node *rchild;
	int val;
}*root;
void dfs(node *p,int tmp)
{
	if(tmp<p->val)
	{
		if(p->lchild!=NULL)
		{
			dfs(p->lchild,tmp);
		}
		else
		{
			node *t = new node;
			t->lchild = NULL;
			t->rchild = NULL;
			t->val = tmp;
			p->lchild = t;
			result[k] = p->val;
			k++;
		}
	}
	if(tmp>p->val)
	{
		if(p->rchild!=NULL)
		{
			dfs(p->rchild,tmp);
		}
		else
		{
			node *t = new node;
			t->lchild = NULL;
			t->rchild = NULL;
			t->val = tmp;
			p->rchild = t;
			result[k] = p->val;
			k++;
		}
	}
}
void PreOrderTraverse

int main()
{
	int n,i,*A;
	cin>>n;
	A=(int*)malloc(sizeof(int)*n);
	cin>>A[0];
	node *t = new node;
	t->lchild = NULL;
	t->rchild = NULL;
	t->val = A[0];
	root = t;
	for(i=1;i<n;i++)
	{
		cin>>A[i];
		dfs(root,A[i]);
	}
	for(i=0;i<n;i++)
	{
		cout<<result[i]<<endl;
	}
	
}






















