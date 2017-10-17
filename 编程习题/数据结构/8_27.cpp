/*#include<iostream>
using namespace std;
int calcMonoSum(int A[], int n) {
        // write code here
        int i,j,sum=0;
        for(i=n-1;i>0;i--)
            {
            for(j=i-1;j>=0;j--)
                {
                if(A[j]<=A[i])
                    {
                    sum += A[j];
                }
            }
        }
        cout<<sum<<endl;
    }
int main()
{
	int a[6]={1,3,5,2,4,6};
	calcMonoSum(a,6);
} 
*/
/*
//相邻最大差 
#include<iostream>
#include<algorithm>
using namespace std;
int AL(int A[],int n)
{
	sort(A,A+n);
	int res=0;
	for(int i=0;i<n-1;i++)
	{
		if(A[i+1]-A[i]>res)
		{
			res=A[i+1] - A[i];
		}
	}
	return res; 
}
int main()
{
	int A[4] = {3,1,5,6};
	AL(A,4);
}

class MaxDivision {
public:
    int findMaxDivision(vector<int> A, int n) {
        // write code here
        sort(A.begin(),A.end());
        int res=0;
        for(int i=0;i<n-1;i++)
        {
            if(A[i+1]-A[i]>res)
            {
                res=A[i+1] - A[i];
            }
        }
        return res; 
        }
};
*/
/*
//奇位数丢弃 
#include<cstdio>
int main()
{
	int n;
	while((scanf("%d",&n))!= EOF)
	{
		int b=1,result;
		while(b<=n+1)
		{
			b<<=1;
		}
		result = (b>>=1) - 1;
		printf("%d\n",result);
	}
	return 0;
} 
*/


#include<iostream>
using namespace std;
int main()
{
	int a[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}
	cout<<a;
} 




















