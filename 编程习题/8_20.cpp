#include<iostream>
using namespace std;

int main()
{
	int n,a=1,i;
	cin>>n;
	for(i=0;i<n-1;i++)
	{
		a *= 2;
	}
	cout<<a<<endl;
}/*
int main()
{
	int a,b,c,d,e,f;
	int n,sum=0;
	cin>>n;
	for(a=0;a<=n/100;a++)
	{
		for(b=0;b<=(n-a*100)/50;b++)
		{
			for(c=0;c<=(n-100*a-b*50)/20;c++)
			{
				for(d=0;d<=(n-100*a-b*50-c*20)/10;d++)
				{
					for(e=0;e<=(n-100*a-b*50-c*20-d*10);e++)
					{
						if((a*100+b*50+c*20+d*10+e)==n)
						{
							sum += 1;
						}
					}
				}
			}
		}
	}
	cout<<sum<<endl;
}
/*
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,min,s,Aresult[100000],Bresult[100000];
	cin>>n;
	int i,num[10000],k=0,l=0;
	long long sum=0;
	for(i=0;i<n;i++)
	{
		cin>>num[i];
	}
	for(s=0;s<n;s++)
	{
		int start = num[s];
		for(i=0;i<n;i++)
		{
			if(num[i]>=start)
			{
				sum += start;
			}
			else
			{
				if(sum!=0)
				{
					Bresult[k]=sum;
					k += 1;
					sum = 0;
				}
			}
		}
		Aresult[l] = sum;
		l += 1;
		sum = 0;

	}
	long long Amax=*max_element(Aresult,Aresult+l);
	long long Bmax=*max_element(Bresult,Bresult+k);
	long long result =max(Amax,Bmax);
	cout<<result<<endl;
}
/*
#include<iostream>
#include<string.h>
using namespace std;
def mergr_sort(lists):
    int count = strlen(lists)
    int mid = int(count/2)
    left[] = mergr_sort(lists[:mid])
    right = mergr_sort(lists[mid:])
    merge(left,right)
def merge(left,right):
    i,j=0,0
    result = []
    while i <len(left) and j <len(right):
        if left[i] <
        */
/*#include<iostream>
#include<string.h>
using namespace std;*/
class StringRotation{
	public:
		string rotateString(string A,int n,int p)
		{
			if(p==n-1)
	            return A;
	        string B;
	        B=A.substr(p+1) + A.substr(0,p+1);
	        return B;
		}
};
