
#include<iostream>
#include<stdlib.h>
void* malloc(size_t size);
using namespace std;
/*˳����� 
int SequenceSearch(int a[],int value,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==value)
		{
			return i;
		}
	}
	return -1;
}
*/
/*���ֲ��ҵ�һ�ַ��� 
int BinarySearch1(int A[],int value,int n)
{
	int low,high,mid;
	low=0;
	high=n-1;
	while(low<=high)
	{
		mid = (low+high)/2;
		if(A[mid]==value)
		{
			return mid;
		}
		if(A[mid]>value)
		{
			high = mid-1;
		}
		if(A[mid]<value)
		{
			low = mid+1;
		}
	}
	return -1;
}
*/
/*���ֲ��ҵĵݹ�ʵ�� 
int BinarySearch2(int A[],int value,int left,int right)
{
	int mid;
	mid = left+(right-left)/2;
	if(left<=right)
	{
		if(A[mid]==value)
		{
			return mid;
		}
		if(A[mid]>value)
		{
			BinarySearch2(A,value,left,mid-1); 
		} 
		if(A[mid]<value)
		{
			BinarySearch2(A,value,mid+1,right);
		}
	}
	return -1;
} 
*/
/*��ֵ���ң��ڶ��ֲ��ҵĻ����Ͻ��иĽ���ͨ���ı�Mid��ֵʹ����ӽ���Ҫ���ҵ��� 
int InsertionSearch(int A[],int value,int left,int right)
{
	int mid;
	mid = left+((value-A[left])*(right-left))/(A[right]-A[left]);
	if(left<=right)
	{
		if(A[mid]==value)
		{
			return mid;
		}
		if(A[mid]>value)
		{
			InsertionSearch(A,value,left,mid-1); 
		} 
		if(A[mid]<value)
		{
			InsertionSearch(A,value,mid+1,right);
		}
	}
	return -1;
}
*/
int main()
{
	int n,*A,i;
	cin>>n;
	A=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		cin>>A[i];
	}
	int value;
	cin>>value;
	//cout<<SequenceSearch(A,value,n);
	//cout<<BinarySearch1(A,value,n);
	//cout<<BinarySearch2(A,value,0,n-1)<<endl;
	cout<<InsertionSearch(A,value,0,n-1)<<endl;
} 
