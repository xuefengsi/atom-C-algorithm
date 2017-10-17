/*
#include<iostream>
using namespace std;
#define maxn 100
int a[maxn];
int n;
void insert_sort(int list[]);
void shell_sort(int list[]);
void bubble_sort(int list[]);
void quick_sort(int list[],int left,int right);
void merge(int list[]);
int main()
{
	int i;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	//insert_sort(a);
	//shell_sort(a);
	//bubble_sort(a);
	//quick_sort(a,0,n-1);
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	
} 

void insert_sort(int list[])
{
	for(int i=0;i<n;i++)
	{
		int j=i-1;
		int key=list[i];
		while(j>=0)
		{
			if(list[j]>key)
			{
				list[j+1] = list[j];
				list[j] = key;
			}
			j--;
		}
	}
}

void shell_sort(int list[])
{
	int step=2;
	int group=int(n/step);
	while(group>0)
	{
		for(int i=0;i<group;i++)
		{
			int j=i+group;
			while(j<n)
			{
				int k=j-group;
				int key=list[j];
				while(k>=0)
				{
					if(list[k]>key)
					{
						list[k+group]=list[k];
						list[k]=key;
					}
					k -= group;
				}
				j += group;
			}
		}
		group = int(group/step);
	}
}

void bubble_sort(int list[])
{
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(list[i]>list[j])
			{
				int t=list[i];
				list[i]=list[j];
				list[j]=t;
			}
		}
	}
}

void quick_sort(int list[],int left,int right)
{
	if(left>=right)
		break;
	int low=left;
	int high=right;
	int key=list[left];
	while(left<right)
	{
		while(left<right&&list[right]>=key)
			right--;
		list[left]=list[right];
		while(left<right&&list[left]<=key)
			left++;
		list[right]=list[left];
	}
	list[right]=key;
	quick_sort(list,low,left-1);
	quick_sort(list,left+1,high);
}

void merge(int list[])
{
	
}
*/
#include<iostream>
using namespace std;
int main()
{
	int n;
}























