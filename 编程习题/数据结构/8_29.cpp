 /*
//��ά����ı��� 
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
//��ά���������Ǳ��� 
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
�����ת��
B[j][i] = A[i][j]
 
*/
/*ħ�����飺��һ��n*n�ľ���������1��n**2������,nΪ������ʹ��ÿһ�С�ÿһ�У�ÿ���Խ��ߣ�����
��ֱ����ӵĺͶ����*
1.��1��ʼ�����֡����ڵ�0�е��м�λ��(n-1)/2�������Ͻ�����һ������
2.λ�ó����Ϸ���Χ��������ײ������Ӧ��λ��
3.λ�ó�����߷�Χ���������ұ����Ӧ��λ��
4.����ҵ���λ���Ѿ� �������ݣ���λ�õ�Ϊ��һ�У�ͬһ��λ��
5.����ҵ���λ��û�з������ݣ��������һ������
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
/*�Խ��㷨�����ݽṹ
ǩע�ķ�ʽ�Ǵ�1-42�ĺ�����ѡ��6�����ظ��ĺ���a0-a5�����췽�Ὺ��6������P0-P5
���һ���ر����P6��
1. ͷ�Ƚ������a0-a5 = p0-p5����6��������ȫ��ͬ 
2.���Ƚ���a�е�5�����������p�У�������һ���������P6 
3.���Ƚ��� a�е�5�����������p�У�������һ�����벻����P6 
4.�ĵȽ���a�е�4�����������P��
5.��Ƚ���a�е�3�������������p�С� 
*/ 

//�㷨һ
//���룺�Խ���������P��ǩע��������A��nΪ�������
//������Խ��������C 
//��������ѭ�����Ƚ�A��P�������ֵ���ܹ�ִ��6*6*n�Ĵ�����ʱ�临�Ӷ�Ϊo(n)
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
	cout<<"����Խ����룺"<<endl;
	int i;
	int p[6];
	for(i=0;i<6;i++)
	{
		cin>>p[i];
	} 
	cout<<"����ǩע���������"<<endl;
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
//�㷨��
//��P�е�6λ����A�е�ÿ�����ݶ����������ƶ���ʽ������polyadd�㷨
//P[0]==A[0][0] ��i��ʾP���±꣬j��ʾA���±꣬��i++,j++���ٱȽ���һ������
//P[0]>A[K][0],j++
//P[0]<A[K][0],i++
//��whileѭ������������6�����12�Σ���������ִ��6n�Σ��ִ��12n�Σ���36nִ�еĿ졣
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
	cout<<"����Խ����룺"<<endl;
	int i;
	int p[6];
	for(i=0;i<6;i++)
	{
		cin>>p[i];
	} 
	sort(p,p+6);
	cout<<"����ǩע���������"<<endl;
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
//�㷨��������һ���������飬��СΪ43�����н�����Ϊiʱ��p[i]=1
//C[k] = C[k] + P[A[k][j]]
//���������ͬ��C[k]��+1������+0
//ִ�д���ʼ��Ϊ6n�Σ�Ϊ����㷨 
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
//�����㷨
//�ڲ����ң���������ҵ����ݿ���ȫ�������ڴ���ٽ��в���
//�ⲿ���ң�������ҵ�������̫���޷����ص��ڴ��У�������������洢�豸��Ӳ�̻�Ŵ�����
//�ռ��ٽ��в���
#include<iostream>
#include<stdlib.h>
void* malloc(size_t size);
using namespace std;
/*���Բ��� 
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
/*���ֲ��� 
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
�岹���ң������ڶ��ֲ��ң��Ƕ��ֲ��ҵ�һ�ָĽ�
���ݷֲ��ľ��ȳ̶� 
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
//����ջʵ�ַ�ת 
#include<iostream>
#define n 5
int Stack[n+1];
int top=-1;
int pop(void);//�Ӷ�ջ��ȡ��Ԫ�� 
char A[n];
void push(int ch);//�����ݷ����ջ 
int isEmpty(void);//�ж϶�ջ�Ƿ�Ϊ�� 
int isFull(void); //�ж϶�ջ�Ƿ�Ϊ�� 
int isOperand(char ch);//�ж��Ƿ�Ϊ������ 
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
//���Զ��� 
#include<iostream>
#define n 5
int Queue[n];
int front = -1;
int rear = -1;
void addq(int data);//��ֵ�ķ�ʽ������data����addq������ 
int delq(void);//��delq�лش�һ������ 
int isEmpty(void);//�ж��Ƿ�Ϊ�գ��ش�һ������ 
int isFull(void);//�ж��Ƿ�Ϊ�����ش�һ������

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



//ѭ������
//ԭ��������ݵ�rear+1Ҫ����(rear+1)%maxq
//ͬʱɾ������ʱfront+1����(front+1)%maxq
//�ж϶����Ƿ�Ϊ����(rear+1)%maxq == front












//����
//ֻҪ���ݱ䶯Ƶ����Ҫά���䶨��Ĵ����ԣ����ʺ�����
//Ѱ�ҽڵ�
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


//ʵ�ֹ���
//������������˳��Ϊ1234567890
//1.�г�����˳��Ϊ0987654321
//2.��Ѱ5���������б�ָ��4
//3.ɾ��13579
//4.�г��б���ʱ˳��Ϊ08642 
//5.��Ѱ5����������5 is not find" 
//����ͷ�ļ� 
#include<iostream>
#include<stdlib.h>
#include<malloc.h>

#define n 10

//����ȫ�ֱ���
typedef struct str_link
{
	int data;
	struct str_link *next; 
} LINKLIST,*PLINKLIST;

PLINKLIST head=NULL;
void addPNode(int data);//���ô�ֵ�ķ�ʽ������data����addPNode������ ,���ﴴ���ڵ� 
void delPNode(int data);//����ɾ���ڵ� 
int findPNode(int data);//Ѱ�ҽڵ� 

int main()
{
	int D[n]={1,2,3,4,5,6,7,8,9,0};
	int i,ret;
	PLINKLIST ptr=NULL;
	//��������� 
	for(i=0;i<n;i++)
	{
		cout<<D[i];
		addPNode(D[i]);
	}
	cout<<endl;
	//�����е����� 
	ptr = head;
	while(ptr!=NULL)
	{
		cout<<ptr->data;
		ptr=ptr->next; 
	} 
	cout<<endl;
	
	//Ѱ�ҽڵ� 
	ret=findPNode(D[4]);
	if(ret==-1)
	{
		cout<<D[4]<<"is not find"<<endl; 
	}
	else
	{
		cout<<"Find"<<endl; 
	}
	
	//ɾ���ڵ� 
	for(i=0;i<n;i=i+2)
	{
		cout<<D[i];
		delPNode(D[i]);
	}
	cout<<endl;
	
	//�����е����� 
	ptr = head;
	while(ptr!=NULL)
	{
		cout<<ptr->data;
		ptr=ptr->next;
	}
	cout<<endl;
	
	//Ѱ�ҽڵ� 
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

//�ɿ�ͷ�����ڵ� 
void addPNode(int data)
{
	PLINKLIST ptr;//�������ͷ��ʼ�� 
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

//ɾ���ڵ� 
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
	if(ptr==NULL)//û���ҵ� 
	{
		cout<<"Node is not find"<<endl;
	}
	else
	{
		if(ptr==head)//�ҵ��Ľڵ��ǿ�ͷ 
		{
			head=ptr->next;
			free(ptr);
		} 
		else//�ҵ��Ľڵ㲻�ǿ�ͷ 
		{
			pre->next=ptr->next;
			free(ptr);
		}
	}
}

//Ѱ�ҽڵ㣬����Ѱ�� 
int findPNode(int data)
{
	PLINKLIST  ptr=head;//�������ͷ��ʼ�� 
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

















































 














































































 






























































 









































