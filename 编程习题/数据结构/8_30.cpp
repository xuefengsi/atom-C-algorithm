//�Ѳ��ɴ�����
//f(n)=f(n-1)+f(n-2),f(1)=f(2)=1 
/*
//ѭ������
#include<iostream>
#include<stdlib.h>
void* malloc(size_t size);
using namespace std;
int main()
{
	int n,i,*A;
	cin>>n;
	A=(int*)malloc(sizeof(int)*n);
	A[0]=A[1]=1;
	for(i=2;i<n;i++)
	{
		A[i]=A[i-1]+A[i-2];
	}
	cout<<A[n-1]<<endl;
} 
*/
/*
//�ݹ�ʵ��
#include<iostream>
using namespace std;
int fib(int n);
int main()
{
	int n;
	cin>>n;
	cout<<fib(n)<<endl;
} 

int fib(int n)
{
	if(n==1||n==2)
	{
		return 1;
	}
	else
	{
		return fib(n-1)+fib(n-2);
	}
}
*/
/*
//�Ѳ��ɴ����У������ú������ǰ��ʱ��f(n+1)/f(n),
//����ƽ�һ������e=1.618033989
int fibrate(int n)
{
	if(n==1||n==2)
	{
		return 1;
	}
	else
	{
		return fibrate(n-1)/fibrate(n-2);
	}
}
*/

/*
//��С������
#include<iostream>
#include<algorithm>
using namespace std;
int gcd(int m,int n);
int main()
{
	int m,n;
	cin>>m>>n;
	cout<<gcd(m,n)<<endl;
} 

int gcd(int m,int n)
{
	int i;
	for(i=
	;i<=min(m,n);i++)
	{
		if(m%i==0&&n%i==0)
		{
			return i;
		}
		else
		{
			return -1;
		}
	}
}
*/
//����������
//����ľ׮���ƶ���������

//1.�Ƚ�A�е�ǰ(n-1)�����̰ᵽ����׮B 
//2.��A�еĵ�n�����̰ᵽĿ��׮C
//3.��Ŀǰ����׮��(n-1)�����̰ᵽC
//4.�Եݹ�Ĺ�ϵ�ٴ���ʣ�µ�(n-1)�����̣���ֻʣ��1������ʱ��������ݹ�
/*
#include<iostream>
using namespace std;
void Hanoi(char A,char B,char C,int n);
int main()
{
	int n=3;
	char from,dest,aux;
	from='A';dest='C';aux='B';
	Hanoi(from,aux,dest,n);
}

void Hanoi(char A,char B,char C,int n)
{
	if(n==1)
	{
		cout<<"disk:"<<n<<" "<<A<<"->"<<C<<endl;
	}
	else
	{
		Hanoi(A,C,B,n-1);
		cout<<"disk:"<<n<<" "<<
		
		
		A<<"->"<<C<<endl;
		Hanoi(B,A,C,n-1);
	}
}
 */
 
 
 
//������
//����ڵ㵽�����
//�������ѽ�����С��������ÿ�γ�����ڵ㣬��ά��ʣ�µĽڵ�Ϊ�ѣ��ظ��ù���
//���������������н���������Ҫ�����ڵ�ĺ͵�ǰ�ѵ����һ��λ�ý���
/* 
#include<iostream>

#define n 10
#define SWAP(x,y) {int t;t=x;x=y;y=t;}
using namespace std;

void createheap(int *A);
void heapsort(int *A);
int main()
{
	int number[n+1]={0,7,9,21,55,23,2,99,44,37,44};
	int i,num;
	for(i=1;i<=n;i++)
	{
		cout<<number[i]<<" ";
	}
	cout<<endl;
	createheap(number);
	for(i=1;i<=n;i++)
	{
		cout<<number[i]<<" ";
	}
	cout<<endl;
	heapsort(number);
	cout<<endl;
} 

void createheap(int number[])
{
	int i,s,p;
	int heap[n+1] = {-1};
	for(i=1;i<=n;i++)
	{
		heap[i]=number[i];
		s=i;
		p=i/2;
		//������ڵ�����ڽڵ�� 
		while(s>=2&&heap[p]>heap[s])
		{
			SWAP(heap[p],heap[s]);//���� 
			s=p;//���ϼ������� 
			p=s/2;
		}
	}
	for(i=1;i<=n;i++)
	{
		number[i]=heap[i];
	}
}

void heapsort(int number[])
{
	int i,m,p,s;
	m=n;
	while(m>1)
	{
		SWAP(number[1],number[m]);//����һ���ڵ����m���ڵ㽻�� 
		m--;
		p=1;
		s=p*2;
		while(s<=m)//��һ�����ѵĵ��� 
		{
			if(s<m&&number[s+1]<number[s])
			{
				s++;
			}
			if(number[p]<=number[s])
			{
				break;
			}
			SWAP(number[p],number[s]);
			p=s;
			s=2*p;
		}
		//�ѵ����������� 
	    for(i=n;i>0;i--)
	    {
	    	cout<<number[i]<<" ";
	    }
	    cout<<endl;
	}
}
*/
//��������� 
//�������Ĳ���
//1.�Ⱥ� ���ڵ�m�Ƚϣ�k==m,���ҳɹ���
//2.k<m������Ƿ��ն˽ڵ㣬���������������ػ� ����1��ԭ���ڵ㻻���������ĸ��ڵ�
//k<m��ͬ��
/*
bintree_search(tree)
{
	ptr = tree;
	while(ptr!=null&&key!=ptr->data)
	{
		if(key<ptr->data)
		{
			ptr=ptr->left;
		}
		else
		{
			ptr=ptr->right;
		}
	}
	return ptr;
} 
*/
//����������Ͷ������ıȽ�
//�������������һ������ʱ��һֱ���²��ң�������ĸ߶�Ϊh����������h�Σ���log(n+1)<=h<=n
//�����������ƽ��ʱ�临�Ӷ�Ϊo(logn)
//������һ��Ķ���������ǰ����������������������ʱ������������ÿ���ڵ㶼Ҫ������ʱ��Ϊn,ƽ��Ϊn/2
//��ʱ�临�Ӷ�Ϊo(n)

//����������ͶѵıȽ�
//���������Ѱ��ĳ���ݵ�ƽ��ʱ����o(logn)������ֻ�߱�ĳ�ڵ�����ݱ��������������еĽڵ�����ݴ������
//����Ҳ��Ҫ��ǰ����������������Ѱ��ĳ���ݣ����Զѵ�ƽ������ʱ��Ϊo(n)
//�����ڲ�����ֵ��ʱ�򣬶ѵ�ʱ�临�Ӷ�Ϊo(1),�����ڶ��������������ֵ��Ҫһֱ�����������ҵ��ն˽ڵ�
//������С��Ҫһֱ�����������ҵ��ն˽ڵ㣬��ƽ��ʱ�伴Ϊ�߶�h��ƽ��ʱ�临�Ӷ�Ϊo(logn)


//����������Ͷ��ֲ��ҵıȽ�
//���ߺ����ƣ������ȱȽ�ĳ�㣬����������ǽ���Ҫ�Ƚϵķ�Χ�����������������ֲ�������߷�Χ���� �ұ߷�Χ
//���ֲ��ҵ�ƽ��ʱ�临�Ӷ�Ϊo(logn)���������߶���������۶��������ʱ����ʱ�临�Ӷ�Ϊo(n)��Ϊ������
//����С�߶��������ʱ����ƽ������ʱ��Ϊo(logn)���ó����ٶ���������ĸ߶ȶ��ڴ����ĳ���ʵ���Ǻ���Ҫ��
//ƽ����������Լ��ٶ���������ĸ߶ȣ���ά�������ԡ� 



















































































