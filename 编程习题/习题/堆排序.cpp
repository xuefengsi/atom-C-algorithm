#include<iostream>
#include<algorithm>
using namespace std;

void swap(int a,int b)
{
	cout<<a<<b<<endl;
	int temp=a;
	a=b;
	b=temp;
	cout<<a<<b<<endl;
}
void HeapAdjust(int *a,int i,int size)
{
	int lchild=2*i;
	int rchild=2*i+1;
	int max=i;
	if(i<=size/2)
	{
		if(lchild<=size&&a[lchild]>a[max])
			max=lchild;
		if(rchild<=size&&a[rchild]>a[max])
			max=rchild;
		if(max!=i)
		{
			swap(a[i],a[max]);
			HeapAdjust(a,max,size);
		}
	}
}

void BuildHeap(int *a,int size)
{
	int i;
	for(i=size/2;i>=1;i--)
	{
		HeapAdjust(a,i,size);
	}
}

void HeapSort(int *a,int size)
{
	BuildHeap(a,size);
	int i;
	for(i=size;i>=1;i--)
	{
		swap(a[1],a[i]);
		HeapAdjust(a,1,i-1);
	}
}

int main()
{
	int i,size;
	cin>>size;
	int a[100];
	for(i=1;i<=size;i++)
		cin>>a[i];
	HeapSort(a,size);
	for(i=1;i<=size;i++)
		cout<<a[i];
	cout<<endl;
}
