//实现单链表的逆置
/*
#include<iostream>
using namespace std;
const int N=6;
typedef int DataType;
typedef struct node
{
	DataType data;
	struct node *next;
}LinkedNode,*LinkList;

LinkList CreateList(DataType a[])
{
	LinkedNode *ListHead = new LinkedNode();
	ListHead->data=a[0];
	ListHead->next=NULL;
	for(int i=N-1;i>=1;i--)
	{
		LinkedNode *p = new LinkedNode();
		p->data=a[i];
		p->next=ListHead->next;
		ListHead->next=p; 
	}
	return ListHead;
}

void PrintList(LinkList ListHead)
{
	if(ListHead==NULL)
		cout<<"The List is empty!"<<endl;
	else
	{
		LinkedNode *p = ListHead;
		while(p!=NULL)
		{
			cout<<p->data<<" ";
			p=p->next; 
		}
		cout<<endl;
	}
}

void ReverseList(LinkedNode *pCur,LinkList &ListHead)
{
	if((pCur==NULL)||(pCur->next==NULL))
		ListHead=pCur;
	else
	{
		LinkedNode *pNext = pCur->next;
		ReverseList(pNext,ListHead);
		pNext->next=pCur;
		pCur->next=NULL;
	} 
}

int main()
{
	int a[N]={1,2,3,4,5,6};
	LinkedNode *list = CreateList(a);
	PrintList(list);
	LinkedNode *pTemp = list;
	ReverseList(pTemp,list);
	PrintList(list);
	
}
*/

//判断两个数组中是否存在相同的数字
//方法一：遍历第一个数组，然后在另外一个数组中进进行二分查找，
//时间复杂度为o(nlogn) 
/*
#include<iostream>
using namespace std;
int findcommon1(int a[],int size1,int b[],int size2);
int findcommon2(int a[],int size1,int b[],int size2);
int main()
{
	int a[5]={1,2,3,4,5};
	int b[5]={4,5,6,7,8};
	//cout<<findcommon1(a,5,b,5)<<endl;
	cout<<findcommon2(a,5,b,5)<<endl;
	
	
} 
int findcommon1(int a[],int size1,int b[],int size2)
{
	int i,num=0;
	for(i=0;i<size1;i++)
	{
		int start=0,end=size2-1,mid;
		while(start<=end)
		{
			mid=(start+end)/2;
			if(a[i]==b[mid])
			{
				num++;
				break;
			}
			else if(a[i]<b[mid])
				end=mid-1;
			else if(a[i]>b[mid])
				start=mid+1;
		} 
	}
	return num;
}

//因为两个数组都已经排好序，所以只要一次遍历即可，时间复杂度为o(n)
//设置两个下标，依次向前推进，比较两个数组的值，小的数组的下标+1 
int findcommon2(int a[],int size1,int b[],int size2)
{
	int i=0,j=0,num=0;
	while(i<size1&&j<size2)
	{
		if(a[i]==b[j])
		{
			num++;
			i++;
			j++;
		}
		else if(a[i]<b[j])
			i++;
		else
			j++;
	}
	return num;
}
*/
/*
//最大子序列问题
//-2,11，-4，13，-5，2，-5，-3，12，-9的 最大子序列为21
//方法一：时间复杂度为o(n2)
#include<iostream>
using namespace std;
int max_sub(int a[],int size);
int max_sub2(int a[],int size);
int main()
{
	int n,i;
	cin>>n;
	int *a=new int[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	//cout<<max_sub(a,n);
	cout<<max_sub2(a,n);
	delete []a;
} 


//方法一 
int max_sub(int a[],int size)
{
	int i,j,sum,max=a[0];
	for(i=0;i<size;i++)
	{
		sum=0;
		for(j=i;j<size;j++)
		{
			sum += a[j];
			if(sum>max)
				max=sum;
		}
	}
	return max;
}

//方法二动态规划 
int max_sub2(int a[],int size)
{
	int i,max=0,sum=0;
	for(i=0;i<size;i++)
	{
		sum += a[i];
		if(sum>max)
			max=sum;
		else if(sum<0)
			sum=0;
	} 
	return max;
} 
*/

//按单词反转字符串
/*
#include<iostream> 
#include<cstdio>
#include<cstring>
#define maxn 100
char s[maxn];
using namespace std;
void reverse_word(char s[],int len);
int main()
{
	gets(s);
	int len = strlen(s);
	cout<<len;
	reverse_word(s,len);
} 

void reverse_word(char s[],int len)
{
	char *res = new char[len+1];
	strcpy(res,s);
	int i,j;
	for(i=0,j=len-1;i<j;i++,j--)
	{
		char temp=res[i];
		res[i]=s[j];
		s[j]=temp;
	}
	int k=0;
	while(k<len)
	{
		i=j=k;
		while(res[j]!=' ')
			j++;
		k=j+1;
		j--;
		for(;i<j;j--,i++)
		{
			char temp=res[i];
			res[i]=res[j];
			res[j]=temp;
		}
	}
}
*/
/*
#include<iostream>
using namespace std;
int main()
{
	int test,i,n,m;
	while(cin>>test)
	{
		while(test--)
		{
			cin>>n>>m;
			int num=0;
			for(i=1;i<=n;i++)
			{
				if(m%i==0&&m/i<=n)
					num++;
			}
			cout<<num<<endl;
		}
	}
}*/
/*
#include<iostream>
using namespace std;
int main()
{
	int test;
	while(cin>>test)
	{
		int a,b,c,d,x0;
		while(test--)
		{
			int res;
			cin>>a>>b>>c>>d>>x0;
			res=3*a*x0*x0+2*b*x0+c;
			cout<<res<<endl;
		}
	}
}
*/
/*
//求众数 
#include<iostream>
#include<cstring>
#define maxn 100
int a[maxn];
int res[maxn];
using namespace std;
int main()
{
	int test,k=0,i;
	char op[15];
	while(cin>>test)
	{
		int n;
		while(test--)
		{
			int len=0,m;
			cin>>n;
			while(n--)
			{
				cin>>op;
				if(strcmp(op,"append")==0)
				{
					cin>>m;
					a[++len]=m;
				}
				else if(strcmp(op,"find")==0)
				{
					cin>>m;
					if(m>0)
						res[k]=a[m];
					else
						res[k]=a[len+m];
					k++;
				}
				else
					len--;
			}
		}
		for(i=0;i<k;i++)
			cout<<res[i]<<endl; 
	}
}
*/
/*
#include<iostream>
#define maxn 100
int a[maxn];
int result[maxn];
using namespace std;
int main()
{
	int test,i,k=0;
	while(cin>>test)
	{
		int n;
		while(test--)
		{
			cin>>n;
			for(i=0;i<n;i++)
				cin>>a[i];
			int res,cur=1,max=0;
			for(i=1;i<n;i++)
			{
				if(a[i]!=a[i-1])
				{
					if(cur>max)
					{
						max=cur;
						res=a[i-1];
					}
					cur=1;
				}
				else
					cur++;
			}
			if(cur>max)
			{
				max=cur;
				res=a[i-1];
			}
			result[k]=res;
			k++;
		}
		for(i=0;i<k;i++)
			cout<<result[i]<<endl;
	}
}
*/

//矩阵旋转
#include<iostream>
#define maxn 100
int a[maxn][maxn];
int b[maxn][maxn];
void rotate();
int m,n;
using namespace std;
int main()
{
	int test,i,j;
	while(cin>>test)
	{
		int d;
		while(test--)
		{
			cin>>m>>n;
			for(i=0;i<m;i++)
				for(j=0;j<n;j++)
					cin>>a[i][j];
			cin>>d;
			int num=d/90;
			while(num--)
				rotate();
			for(i=0;i<m;i++)
			{
				for(j=0;j<n;j++)
					cout<<a[i][j]<<" ";
				cout<<endl;
		    }
		    cout<<endl;
		}
	}
} 
void rotate()
{
	int i,j;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			b[j][m-i-1]=a[i][j];
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			a[i][j]=b[i][j];
	int t=m;
	m=n;
	n=t;
}

























































































