 /*
//二维数组的遍历 
#include<stdio.h>
int main()
{
	int A[4][6],i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<6;j++)
		{
			A[i][j] = i*6+j;
			printf("[%d][%d]=%d ",i,j,A[i][j]);
		}
		printf("\n");
	}
	return 0;
} 
*/
/*
//二维数组上三角遍历 
#include<stdio.h>
int main()
{
	int A[5][5],i,j,count=0;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			A[i][j] = 0;;
		}
		for(j=i;j<5;j++)
		{
			A[i][j] =++count;
		}
		for(j=0;j<5;j++)
		{
			printf("[%d][%d]=%d ",i,j,A[i][j]);
		}
		printf("\n");
	}
	return 0;
}
*/

/*
矩阵的转置
B[j][i] = A[i][j]
 
*/
/*魔术方块：在一个n*n的矩阵中填入1到n**2的数字,n为奇数，使得每一行。每一列，每条对角线，横线
及直线相加的和都相等*
1.由1开始填数字。放在第0行的中间位置(n-1)/2，往左上角填入一个数字
2.位置超出上方范围，则用最底层相相对应的位置
3.位置超出左边范围，则用最右边相对应的位置
4.如果找到的位置已经 放入数据，则位置调为下一行，同一列位置
5.如果找到的位置没有放入数据，则放入下一个数字
#include<stdio.h>
#define n 5
void square(int M[n][n]);
int main(int)
{
	int M[n][n] = {0};
	int i,j;
	square(M);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("M[%d][%d]=%d ",i,j,M[i][j]);
		}
		printf("\n");
	}
} 

void square(int M[n][n])
{
	int p,q,k;
	p = 0;
	q = (n-1)/2;
	M[0][q] = 1;
	for(k=2;k<=n*n;k++)
	{
		p = (p-1+n)%n;
		q = (q-1+n)%n;
		if(M[p][q] > 0)
		{
			p = (p+1)%n;
			M[p][q] = k;
		}
		else
		{
			M[p][q] = k;
		}
	}
}
*/ 
/*对奖算法与数据结构
签注的方式是从1-42的号码中选出6个不重复的号码a0-a5，主办方会开出6个号码P0-P5
外加一个特别号码P6。
1. 头等奖：如果a0-a5 = p0-p5，即6个号码完全相同 
2.二等奖：a中的5个号码出现在p中，且另外一个号码等于P6 
3.三等奖： a中的5个号码出现在p中，且另外一个号码不等于P6 
4.四等奖：a中的4个号码出现在P中
5.五等奖：a中的3三个号码出现在p中。 
*/ 

//算法一
//输入：对奖号码数组P，签注号码数组A，n为号码个数
//输出：对奖结果数组C 
//用了三个循环来比较A和P的数组的值，总共执行6*6*n的次数，时间复杂度为o(n)
/* 
#include<iostream>
using namespace std;
void lottol(int p[],int A[][6],int C[],int n) 
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<=5;j++)
		{
			for(k=0;k<=5;k++)
			{
				if(A[i][j] == p[k])
				{
					C[i] =C[i] + 1;
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<C[i]<<endl;
	}
} 
int main()
{
	cout<<"输入对奖号码："<<endl;
	int i;
	int p[6];
	for(i=0;i<6;i++)
	{
		cin>>p[i];
	} 
	cout<<"输入签注号码个数："<<endl;
	int n=2,j;
	cin>>n;
	int C[n];
	int A[n][6];
	for(i=0;i<n;i++)
	{
		C[i] = 0;
		for(j=0;j<6;j++)
		{
			cin>>A[i][j];
		}
	} 
	lottol(p,A,C,n);
}
*/
//算法二
//将P中的6位数和A中的每行数据都排序，用类似多项式佳宁发polyadd算法
//P[0]==A[0][0] 用i表示P的下标，j表示A的下标，则i++,j++，再比较下一个号码
//P[0]>A[K][0],j++
//P[0]<A[K][0],i++
//用while循环，次数最少6次最多12次，即最好情况执行6n次，最坏执行12n次，比36n执行的快。
/* 
#include<iostream>
#include<algorithm>
using namespace std;
void lotto2(int p[],int A[][6],int C[],int n)
{
	int i,j,k;
	for(k=0;k<n;k++)
	{
		i=0,j=0;
		while(i<6&&j<6)
		{
			if(p[i]==A[k][j])
			{
				i++;
				j++;
				C[k] += 1;
			}
			else if(p[i]>A[k][j])
			{
				j++;
			}
			else if(p[i]<A[k][i])
			{
				i++;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<C[i]<<endl;
	}
}

int main()
{
	cout<<"输入对奖号码："<<endl;
	int i;
	int p[6];
	for(i=0;i<6;i++)
	{
		cin>>p[i];
	} 
	sort(p,p+6);
	cout<<"输入签注号码个数："<<endl;
	int n=2,j;
	cin>>n;
	int C[n];
	int A[n][6];
	for(i=0;i<n;i++)
	{
		C[i] = 0;
		for(j=0;j<6;j++)
		{
			cin>>A[i][j];
		}
		sort(A[i][0],A[i][6]);
	} 
	lotto2(p,A,C,n);
}
*/
//算法三。借助一个辅助数组，大小为43，当中奖号码为i时，p[i]=1
//C[k] = C[k] + P[A[k][j]]
//如果号码相同，C[k]会+1，否则+0
//执行次数始终为6n次，为最佳算法 
/*
void lotto3(int p[],int A[][6],int C[],int n)
{
	int k,j;
	for(k=0;k<n;k++)
	{
		for(j=0;j<6;j++)
		{
			C[k] = C[k] + p[A[k][j]];
		}
	}
} 
*/
//查找算法
//内部查找：如果待查找的数据可以全部加载内存后再进行查找
//外部查找：如果查找的数据量太大，无法加载到内存中，必须借助辅助存储设备（硬盘或磁带）的
//空间再进行查找
#include<iostream>
#include<stdlib.h>
void* malloc(size_t size);
using namespace std;
/*线性查找 
int linear_search(int A[],int n,int key)
{
	int i=0;
	while(i<n)
	{
		if(A[i]==key)
		{
			return i;
		}
		else
		{
			i++;
		}
	}
	return -1;
} 
*/
/*二分查找 
int Binary_search(int A[],int key,int low,int upper)
{
	int mid=0;
	while(low<upper)
	{
		mid = (int)((low+upper)/2);
		if(key==A[mid])
		{
			return mid;
		}
		else if(key>A[mid])
		{
			low = mid + 1;
		}
		else if(key<A[mid])
		{
			upper = mid - 1;
		}
	}
	return -1;
}
*/
/*
插补查找：类似于二分查找，是二分查找的一种改进
数据分布的均匀程度 
mid = low+(x-A[low])(upper-low)/(A[upper]-A[low] 
*/
/*
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
	//cout<<linear_search(A,n,value)<<endl;
	//cout<<Binary_search(A,value,0,n-1)<<endl;
}
*/






/*
//利用栈实现反转 
#include<iostream>
#define n 5
int Stack[n+1];
int top=-1;
int pop(void);//从堆栈中取出元素 
char A[n];
void push(int ch);//将数据放入堆栈 
int isEmpty(void);//判断堆栈是否为空 
int isFull(void); //判断堆栈是否为满 
int isOperand(char ch);//判断是否为操作数 
int main()
{
	int i;
	//int A[n]={1,3,5,7,9};
	cin>>A;
	for(i=0;i<n;i++)
	{
		push(A[i]);
	}
	for(i=0;i<n;i++)
	{
		A[i]=pop();
	}
	for(i=0;i<n;i++)
	{
		cout<<A[i];
	}
	cout<<endl;
} 
int pop(void)
{
	return Stack[top--];
}
void push(int ch)
{
	Stack[++top]=ch;
}
int isEmpty(void)
{
	if(top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isFull(void)
{
	if(top==n-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isOperand(char ch)
{
	int ret;
	switch(ch)
	{
		case '+' :
		case '-' :
		case '*' :
		case '/' :
		case '(' :
		case ')' :
			ret = 0;
			break;
		default:
			ret = 1;
			break;
	}
	return ret;
}

*/







/*
//线性队列 
#include<iostream>
#define n 5
int Queue[n];
int front = -1;
int rear = -1;
void addq(int data);//传值的方式把整数data传入addq函数中 
int delq(void);//从delq中回传一个整数 
int isEmpty(void);//判断是否为空，回传一个整数 
int isFull(void);//判断是否为满，回传一个整数

int main()
{
	int i;
	int A[n]={1,3,5,7,9};
	for(i=0;i<n;i++)
	{
		cout<<A[i];
		addq(A[i]);
	}
	cout<<endl;
	for(i=0;i<n;i++)
	{
		cout<<delq();
	}
	cout<<endl;
} 
void addq(int data)
{
	if(isFull())
	{
		cout<<"Queue Is Full"<<endl;
	}
	else
	{
		Queue[++rear]=data;
	}
}
int delq(void)
{
	if(isEmpty())
	{
		cout<<"Queue Is Empty"<<endl;
	}
	else
	{
		return Queue[++front];
	}
}
int isEmpty(void)
{
	if(front==rear)
	{
		return 1;
	} 
	else
	{
		return 0;
	}
}
int isFull(void)
{
	if(rear==n-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
*/



//循环队列
//原先添加数据的rear+1要换成(rear+1)%maxq
//同时删除数据时front+1换成(front+1)%maxq
//判断队列是否为满，(rear+1)%maxq == front












//链表
//只要数据变动频繁且要维持其定义的次序性，都适合链表
//寻找节点
/*
int lsearch(int data)
{
	llink = head;
	ans = -1;
	for(i=0;i<n;i++)
	{
		if(A[0][llink] > data)
		{
			return ans;
		}
		else
		{
			ans = llink;
			link = A[1][llink];
		}
	}
	return ans;
} 
*/


//实现功能
//假设输入数据顺序为1234567890
//1.列出链表顺序为0987654321
//2.找寻5，结果输出列表指标4
//3.删除13579
//4.列出列表，此时顺序为08642 
//5.找寻5，结果输出“5 is not find" 
//声明头文件 
#include<iostream>
#include<stdlib.h>
#include<malloc.h>

#define n 10

//声明全局变量
typedef struct str_link
{
	int data;
	struct str_link *next; 
} LINKLIST,*PLINKLIST;

PLINKLIST head=NULL;
void addPNode(int data);//利用传值的方式把整数data传入addPNode函数中 ,用语创建节点 
void delPNode(int data);//用于删除节点 
int findPNode(int data);//寻找节点 

int main()
{
	int D[n]={1,2,3,4,5,6,7,8,9,0};
	int i,ret;
	PLINKLIST ptr=NULL;
	//输入的数据 
	for(i=0;i<n;i++)
	{
		cout<<D[i];
		addPNode(D[i]);
	}
	cout<<endl;
	//链表中的数据 
	ptr = head;
	while(ptr!=NULL)
	{
		cout<<ptr->data;
		ptr=ptr->next; 
	} 
	cout<<endl;
	
	//寻找节点 
	ret=findPNode(D[4]);
	if(ret==-1)
	{
		cout<<D[4]<<"is not find"<<endl; 
	}
	else
	{
		cout<<"Find"<<endl; 
	}
	
	//删除节点 
	for(i=0;i<n;i=i+2)
	{
		cout<<D[i];
		delPNode(D[i]);
	}
	cout<<endl;
	
	//链表中的数据 
	ptr = head;
	while(ptr!=NULL)
	{
		cout<<ptr->data;
		ptr=ptr->next;
	}
	cout<<endl;
	
	//寻找节点 
	ret=findPNode(D[4]);
	if(ret==-1)
	{
		cout<<D[4]<<"is not find"<<endl; 
	}
	else
	{
		cout<<"Find"<<endl; 
	}
}

//由开头新增节点 
void addPNode(int data)
{
	PLINKLIST ptr;//从链表的头开始看 
	ptr = (PLINKLIST)malloc(sizeof(PLINKLIST));
	if(ptr==NULL)
	{
		cout<<"ERROR";
	}
	else
	{
		ptr->data=data;
		ptr->next=head;
		head=ptr;
	}
}

//删除节点 
void delPNode(int data)
{
	PLINKLIST pre=head,ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->data==data)
		{
			break;
		}
		pre=ptr;
		ptr=ptr->next;
	}
	if(ptr==NULL)//没有找到 
	{
		cout<<"Node is not find"<<endl;
	}
	else
	{
		if(ptr==head)//找到的节点是开头 
		{
			head=ptr->next;
			free(ptr);
		} 
		else//找到的节点不是开头 
		{
			pre->next=ptr->next;
			free(ptr);
		}
	}
}

//寻找节点，往后寻找 
int findPNode(int data)
{
	PLINKLIST  ptr=head;//从链表的头开始看 
	int index=0;
	while(ptr!=NULL)
	{
		if(ptr->data==data)
		{
			return index;
		}
		ptr=ptr->next;
		index++;
	}
	return -1;
}

















































 














































































 






























































 









































