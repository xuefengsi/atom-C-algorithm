/*#include<iostream>
#include<stdlib.h>
void* malloc(size_t size);
using namespace std;
int main()
{
	int test,n,*A,i,j,k,*count,t=0;
	cin>>test;
	count=(int*)malloc(sizeof(int)*test);
	while(test>0)
	{
		cin>>n;
		A=(int*)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
		{
			cin>>A[i];
		}
		int number=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					if((A[i]+A[j])==A[k])
					{
						number++;
					}
				}
			}
		}
		count[t]=number;
		t += 1;
		//cout<<count<<endl;	
		test -= 1;
	}
	for(i=0;i<t;i++)
	{
		cout<<count[i]<<endl;
	}
} 
*/
/*
#include<iostream>
#include<cstring>
#define maxn 105
using namespace std;

char a[maxn];
char result[maxn][maxn];
int main()
{
	int test,n,len,count=0,i,k=0,j=0;
	cin>>test;
	while(test>0)
	{
		cin>>a;
		len=strlen(a);
		for(i=0;i<len;i++)
		{
			if(a[i]=='1')
			{
				result[k][j]=a[i];
				j++;
				count += 1;
				if(count==5)
				{
					i++;
					count=0;
				}
			}
			else
			{
				result[k][j]=a[i];
				j++;
				count=0;
			}
		}
		k++;
		j=0;
		test--;
	}
	for(i=0;i<k;i++)
	{
		for(j=0;j<len;j++)
		{
			cout<<result[i][j];
		}
		cout<<endl;
	}
}
*/
/*
#include<iostream>
#include<stdlib.h>
void* malloc(size_t size); 
using namespace std;
int main()
{
	int test,n,m,i,k=0,*result;
	cin>>test;
	result=(int*)malloc(sizeof(int)*test);
	while(test>0)
	{
		cin>>n>>m;
		int count=0;
		for(i=1;i<=n;i++)
		{
			if((m%i==0)&&(m/i<=n))
			{
				count++;
			}
		}
		result[k]=count;
		k++;
		test--;
	}
	for(i=0;i<k;i++)
	{
		cout<<result[i]<<endl;
	}
}
*/
/*
#include<iostream>
#include<cstring>
#define maxn 100
#define maxo 10
using namespace std;
char s[maxn];
char operate[maxo];
char result[maxn][maxn];
int main()
{
	cin>>s;
	int test,start,end,len,k=0,j=0;
	len=strlen(s);
	cin>>test;
	while(test>0)
	{
		cin>>operate>>start>>end;
		if(operate=='CUT')
		{
			for(i=0;i<s;i++)
			{
				if(i<start||i>end)
				{
					result[k][j]=s[i];
					j++;
				}
			}
			strcpy(result[k][],s);
			k++;
			j=0;
		}
		else if(operate=='COPY')
		{
			
		}
	}
}
*/


/*
#include<iostream>
using namespace std;

int main()
{
    int tes,n,m;
    int i;
    while(cin>>tes)
    {
        while(tes--)
        {
            cin>>n>>m;

            int cnt=0;
            for(i=1; i<=n; i++)
            {
                if(m%i==0&&m/i<=n)
                    cnt++;
            }
            cout<<cnt<<endl;
        }
    }
    return 0;
}

/*
2
11111010
1111100
*/
/*list 
#include<iostream>
using namespace std;
#include<cstring>
#define maxn 100
#define maxo 15
int a[maxn];
char op[maxo];
int result[maxn][maxn];
int num[maxn];
int main()
{
	int test,m,d,k=0,i,h=0,j,f=0;
	cin>>test;
	while(test>0)
	{
		cin>>m;
		int l=0,p=0;
		for(i=0;i<m;i++)
		{
			cin>>op;
			if(strcmp(op,"append")==0)
			{
				cin>>d;
				a[k]=d;
				k++;
			}
			else if(strcmp(op,"find")==0)
			{
				cin>>d;
				if(d>0)
				{
					result[h][l]=a[d-1];
					l++;
				}
				else
				{
					result[h][l]=a[k+d];
					l++;
				}
				p++;
			}
			else
			{
				k--;
			}
		}
		h++;
		num[f]=p;
		f++;
		test--;
	}
	for(i=0;i<h;i++)
	{
		for(j=0;j<num[i];j++)
		{
			cout<<result[i][j]<<endl;
		}
	}
}
*/
/*求众数 
#include<iostream>
#include<stdlib.h>
#define maxn 100
void* malloc(size_t size);
int *p = (int*)malloc(sizeof(int)*maxn);
int a[maxn];
int result[maxn];
using namespace std;
int main()
{
	int test,n,i,k=0;
	cin>>test;
	while(test>0)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<maxn;i++)
		{
			p[i]=0;
		}
		int max=0;
		for(i=0;i<n;i++)
		{
			p[a[i]]++;
			if(p[a[i]]>p[max])
			{
				max=a[i];
			}
			else if(p[a[i]]==p[max])
			{
				max = (a[i]>max?max:a[i]);
			}
		}
		result[k]=max;
		k++;
		test--;
	}
	for(i=0;i<k;i++)
	{
		cout<<result[i]<<endl;
	}
}
*/
/*中位数 
#include<iostream>
#define maxn 100
int a[maxn];
float result[maxn];
using namespace std;
int main()
{
	int test,n,i,k=0;
	cin>>test;
	while(test>0)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		if(n%2!=0)
		{
			int mid=n/2;
			result[k]=a[mid];
			//result[k]=("%.1f" % float(a[mid]));
			k++;
		}
		else
		{
			int t = (a[n/2]+a[n/2-1])*5;
			if(t%10==0)
			{
				result[k]=t/10;
				k++;
			}
			else
			{
				result[k]=("%.1f",float(t)/10);
				k++;
			}
		}
		test--;
	}
	for(i=0;i<k;i++)
	{
		cout<<result[i]<<endl;
	}
}
*/
/*
#include<iostream>
#define maxn 100
using namespace std;
char result[maxn][maxn];
int a[maxn];
int b[maxn];
int num[maxn];
int main()
{
	int test,n,m,i,o=0,j,p,f=0;
	cin>>test;
	while(test>0)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<n;i++)
		{
			for(j=i;j<n;j++)
			{
				if(a[i]>a[j])
				{
					int mid=a[i];
					a[i]=a[j];
					a[j]=mid;
				} 
			}
		}
		cin>>m;
		for(i=0;i<m;i++)
		{
			cin>>b[i];
		}
		int h=0;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[n-1]<b[i])
				{
					result[o][h]="NULL"
					h++;
				}
				else
				{
					int min=a[n-1]-b[i];
					if(a[j]>=b[i]&&(a[j]-b[i])<min)
					{
						min=a[j]-b[i];
						p=j;
					}
				}
			}
			result[o][h]=a[p];
			h++;
		}
		o++;
		num[f]=h;
		f++;
		test--;
	}
	for(i=0;i<o;i++)
	{
		for(j=0;j<num[i];j++)
		{
			cout<<result[i][j]<<endl;
		}
	}
}
*/























