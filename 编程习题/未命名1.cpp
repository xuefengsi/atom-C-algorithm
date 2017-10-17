/*#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	long long h,i;
	cin>>h;
	for(i=sqrt(h);i>=0;i--)
	{
		if((i+i*i)<=h)
		{
			cout<<i<<endl;
			break;
		}
	}
}
*/
/*
#include<iostream>
#include<string.h>
using namespace std;
void GetPowerSet(int i,char A[],char B[],char C[])
{
	if(i==strlen(A))
	{
		cout<<strlen(B);
	}
	else
	{
		char x=A[i];
		int k=strlen(B);
		B[k]=x;GetPowerSet(i+1,A,B,C);//左子树 
		B[k]=0;GetPowerSet(i+1,A,B,C);//右子树 
	}
}

int main()
{
	char A[10];
	cin>>A;
	char C[10];
	cin>>C;
	int size_B=strlen(A)+1;
	char *B=new char[size_B];
	memset(B,0,size_B);//在头文件string.h中声明 将B中的成员全部初始化为0 
	GetPowerSet(0,A,B,C);
	delete B;
	return 0;
}
*/
#include<iosteam>
#include<string.h>
using namespace std;
int main
