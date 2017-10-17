#include<iostream>
using namespace std;

int BinarySearch(int a[],int len,int value,bool IsLeft)
{
	int left=0;
	int right = len-1;
	int last;
	while(left<=right)
	{
		int mid = (left+right)/2;
		if(value<a[mid])
			right = mid-1;
		else if(value>a[mid])
			left=mid+1;
		else
		{
			last = mid;
			if(IsLeft)
				right=mid-1;
			else
				left=mid+1;
		}
	}
	return last;
}
int main()
{
	int a[5] = {1,1,2,2,3};
	int left = BinarySearch(a,5,2,true);
	int right = BinarySearch(a,5,2,false);
	int count = right - left + 1;
	cout<<count<<endl;
}
