#include<iostream>
using namespace std;

int MaxSubseqSum1(int a[],int n)//o(n^3)
{
	int MaxSum = 0;
	for(int i=0;i<n;i++)//i为子列左边界 
	{
		for(int j=i;j<n;j++)//j为子列右边界 
		{
			int TemSum = 0;
			for(int k=i;k<=j;k++)//遍历子列中的元素 
			{
				TemSum += a[k];
			}
			if(TemSum>MaxSum)
				MaxSum = TemSum;
		}
	}
	return MaxSum;
}

int MaxSubseqSum2(int a[],int n)//o(n^2) 
{
	int MaxSum = 0;
	for(int i=0;i<n;i++)
	{
		int TemSum = 0;
		for(int j=i;j<n;j++)
		{
			TemSum += a[j];
			if(TemSum>MaxSum)
				MaxSum = TemSum;
		}
	}
	return MaxSum;
} 

int MaxSubseqSum3(int a[],int n)//o(n)
{
	int MaxSum,TempSum;
	MaxSum=TempSum=0;
	for(int i=0;i<n;i++)
	{
		TempSum += a[i];
		if(TempSum>MaxSum)
			MaxSum=TempSum;
		else if(TempSum<0)
			TempSum = 0;
	}
	return MaxSum;
}

int SecondMax(int a[],int n)
{
	int number=a[0];
	int result=number;
	for(int i=1;i<n;i++)
	{
		if(a[i]>number)
		{
			result = number;
			number = a[i];
		}
		else if(a[i]>result)
		{
			result = a[i];
		}
	}
	return result;
}
int main()
{
	int a[5]={-1,3,-2,4,5};
  	//cout<<MaxSubseqSum3(a,5)<<endl;
  	cout<<SecondMax(a,5)<<endl;
} 
