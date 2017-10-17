//费波纳茨数列
//f(n)=f(n-1)+f(n-2),f(1)=f(2)=1 
/*
//循环计算
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
//递归实现
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
//费波纳茨数列：当你用后项除以前项时：f(n+1)/f(n),
//最后会逼近一个常数e=1.618033989
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
//最小公因子
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
//河内塔问题
//三根木桩，移动铁盘问题

//1.先将A中的前(n-1)个铁盘搬到辅助桩B 
//2.将A中的第n个铁盘搬到目的桩C
//3.将目前辅助桩的(n-1)个铁盘搬到C
//4.以递归的关系再处理剩下的(n-1)个铁盘，但只剩下1个铁盘时，则结束递归
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
 
 
 
//堆排序
//插入节点到最大推
//利用最大堆进行由小到大排序，每次抽出根节点，再维护剩下的节点为堆，重复该过程
//若是在数组数据中进行排序，需要将根节点的和当前堆的最后一个位置交换
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
		//如果父节点比现在节点大 
		while(s>=2&&heap[p]>heap[s])
		{
			SWAP(heap[p],heap[s]);//交换 
			s=p;//往上继续处理 
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
		SWAP(number[1],number[m]);//将第一个节点与第m个节点交换 
		m--;
		p=1;
		s=p*2;
		while(s<=m)//做一次最大堆的调整 
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
		//堆调整过的数据 
	    for(i=n;i>0;i--)
	    {
	    	cout<<number[i]<<" ";
	    }
	    cout<<endl;
	}
}
*/
//二叉查找树 
//二叉树的查找
//1.先和 根节点m比较，k==m,查找成功，
//2.k<m；如果是非终端节点，查找左子树，在重回 步骤1，原根节点换成左子树的根节点
//k<m，同理。
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
//二叉查找树和二叉树的比较
//二叉查找树查找一个数据时，一直往下查找，如果树的高度为h，则最多查找h次，且log(n+1)<=h<=n
//二叉查找树的平均时间复杂度为o(logn)
//而对于一般的二叉树，用前序中序后序遍历来查找数据时，其最差情况是每个节点都要遍历，时间为n,平均为n/2
//其时间复杂度为o(n)

//二叉查找树和堆的比较
//二叉查找树寻找某数据的平均时间是o(logn)，而堆只具备某节点的数据比左右子树中所有的节点的数据打的性质
//堆中也是要用前序中序后序遍历法来寻找某数据，所以堆的平均查找时间为o(n)
//但是在查找最值的时候，堆的时间复杂度为o(1),而对于二叉树，查找最大值需要一直沿着右子树找到终端节点
//查找最小数要一直沿着左子树找到终端节点，其平均时间即为高度h，平均时间复杂度为o(logn)


//二叉查找树和二分查找的比较
//两者很相似，都是先比较某点，二叉查找树是接着要比较的范围是左右子树，二二分查找是左边范围或者 右边范围
//二分查找的平均时间复杂度为o(logn)，而已最大高度情况来讨论二叉查找树时，其时间复杂度为o(n)，为最差情况
//以最小高度情况讨论时，其平均查找时间为o(logn)，得出减少二叉查找树的高度对于此树的程序实现是很重要的
//平衡二叉树可以减少二叉查找树的高度，且维持其特性。 



















































































