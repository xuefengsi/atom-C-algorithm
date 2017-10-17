/*//计数排序算法 
#include<iostream>
using namespace std;
void CountSort(int A[],int B[],int n)
{
	int i,j,cnt=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(A[i]>A[j])
			{
				cnt++;
			}
		}
		B[cnt] = A[i];
		cnt=0;
	}
	for(i=0;i<n;i++)
	{
		cout<<B[i]<<" ";
	}
}
int main()
{
	int n,A[100],B[100];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	CountSort(A,B,n);
	
} */

/*
//求主元素 
#include<iostream>
using namespace std;
int Majority(int A[],int n)
{
	int c,i,count=1;
	c=A[0];
	for(i=1;i<n;i++)
	{
		if(A[i]==c)
		{
			count++;
		}
		else if(count>0)
		{
			count--;
		}
		else
		{
			c=A[i];
			count = 1;
		}
	}
	if(count>0)
	{
		for(i=count=0;i<n;i++)
		{
			if(A[i]==c)
			{
				count++;
			}
		}
	}
	if(count>n/2)
	{
		return c;
	}
	else
	{
		return -1;
	}
}
int main()
{
	int n,i;
	cin>>n;
	int A[100];
	for(i=0;i<n;i++)
	{
		cin>>A[i];
	}
	cout<<Majority(A,n)<<endl;
}*/
/*
//采用计数排序思想的算法,时间复杂度为o(n),空间复杂度为o(n) 
#include<iostream>
#include<stdlib.h>
void* malloc(size_t size);
using namespace std;
int Majority(int A[],int n)
{
	int k,*p,max;
	p=(int *)malloc(sizeof(int)*n);//申请辅助计数数组
	for(k=0;k<n;k++)
	{
		p[k]=0;//计数数组清0 
	}
	max = 0;
	for(k=0;k<n;k++)
	{
		p[A[k]]++;
		if(p[A[k]] > p[max])
		{
			max = A[k];
		}
	}
	if(p[max]>n/2)
	{
		return max;
	}
	else
	{
		return -1;
	}
}
int main()
{
	int n,*A;
	A=(int *)malloc(sizeof(int)*n);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	cout<<Majority(A,n)<<endl;
} 
*/
/*
//中位数
#include<iostream>
#include<stdlib.h>
void* malloc(size_t size);
using namespace std;
int Search(int A[],int B[],int n)
{
	int s1=0,e1=n-1,s2=0,e2=n-1,mid1,mid2;
	while(s1!=e1||s2!=e2)
	{
		mid1=(s1+e1)/2;
		mid2=(s2+e2)/2;
		if(A[mid1]==B[mid2])
		{
			return A[mid1];
		}
		if(A[mid1] < B[mid2])
		{//考虑奇数和偶数，保证两个子数组元素个数相等 
			if((s1+e1)%2 == 0)//如果是奇数个 
			{
				s1=mid1;//舍弃A中间点以前保留中间的 
				e2=mid2;//舍弃B中间的以后保留中间的 
			}
			else
			{
				s1=mid1+1;//舍弃A中间点及以前部分 
				e2=mid2;//舍弃B以后部分 
			}
		}
		else
		{
			if((s1+e1)%2 == 0)
			{
				s2=mid2;
				e1=mid1;
			}
			else
			{
				s2=mid2+1;
				e1=mid1;
			}
		}
	}
	return (A[s1]<B[s2] ? A[s1]:B[s2]);
}
int main()
{
	int n,*A,*B;
	cin>>n;
	A=(int*)malloc(sizeof(int)*n);
	B=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>B[i];
	}
	cout<<Search(A,B,n)<<endl;
} 
*/
/*
//字串左移动p位 ，第一种方法 
#include<iostream>
#include<stdlib.h>
void* malloc(size_t size);
using namespace std;
void left_p(int A[],int n,int p)
{
	while(p--)
	{
		int t=A[0];
		for(int i=1;i<n;i++)
		{
			A[i-1]=A[i];
		}
		A[n-1]=t;
	}
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<" ";
	}
}
int main()
{
	int n,*A,p;
	cin>>n;
	cin>>p;
	A=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	left_p(A,n,p);
} 
//虽然该算法可以实现，但是时间复杂度为o(o*n)，太高。 
*/


//第二种方法 时间复杂度为o(n)，空间复杂度为o(1) 
#include<iostream>
#include<stdlib.h>
void * malloc(size_t size);
using namespace std;
void reverse(int A[],int left,int right)
{//实现反转 
	while(left<right)
	{
		int t=A[left];
		A[left] = A[right];
		A[right] = t;
		left++;
		right--;
	}
}
void leftshift(int A[],int n,int p)
{
	if(p>0&&p<n)
	{
		reverse(A,0,n-1);
		reverse(A,0,n-p-1);
		reverse(A,n-p,n-1);
	}
}
int main()
{
	int n,*A,p;
	cin>>n;
	cin>>p;
	A=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	leftshift(A,n,p);
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<" "; 
	}
} 

/*
//链表的插入和删除
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int num;
	char str[20];
	struct node *next;
} ;

main()
{
	struct node *creat();
	struct node *insert();
	struct node *delet();
	void print();
	struct node *head;
	char str[20];
	int n;
	head = NULL;
	head = creat(head);
	print(head);
	printf("\n input inserted num,name:\n");
	gets(str);
	n = atoi(str);
	gets(str);
	head = insert(head,str,n);
	print(head);
	return;
}

struct node *creat(struct node *head)
{
	char temp[30];
	struct node *p1,*p2;
	p1=p2=(struct node*)malloc(sizeof(struct node));
	printf("input num,name:\n");
	printf("exit:double times Enter);
	gets(temp);
    gets(pl->str);
    pl->num=atoi(temp);
    pl->next=NULL;
	while(strlen(pl->str)>0)
    {
        if(head==NULL)//if?the?chain?is?null??
             head=pl;//??
        else
             p2->next=pl;//set?the?p2->next?NULL??
        p2=pl;//??
    pl=(struct node*)malloc(sizeof(struct?node));
    printf ("input?num,?name:?\n");
    printf("exit:double?times?Enter!\n");
    gets(temp);
    gets(pl->str);
    pl->num=atoi(temp);
    pl->next=
	ukNULL;
    }
    return head;
}*/






















