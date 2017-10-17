//递推和递归的差异
//递推像是多米诺骨牌，根据前面几个得到后面的
//递归是大事化小，比如汉诺塔问题
//如果一个问题可以递推也可以递归，采用递推，因为其效率比递归高


//分治
//1.分解 2.求解 3.合并

//贪心
//找零方案
//100 50 10 5 2 1 0.5 0.2 0.1
#include<iostream>
#define maxn 9
using namespace std;
int parvalue[maxn]={10000,5000,2000,1000,500,100,50,10};
int num[maxn]={0};
int exchange(int n);
int main()
{
	int i;
	float m;
	cin>>m;
	exchange(int(100*m));
	for(i=0;i<maxn;i++)
	{
		if(num[i]>0)
		{
			cout<<float(parvalue[i]/100.0)<<":"<<num[i]<<endl;
		}
	}
	cout<<endl;
} 

int exchange(int n)
{
	int i,j;
	for(i=0;i<maxn;i++)
	{
		if(n>parvalue[i])
		{
			break;//找到比n小的最大面额 
		}
	}
    while(n>0&&i<maxn)
    {
    	if(n>=parvalue[i])
    	{
    		n-=parvalue[i];
    		num[i]++;
    	}
    	else if(n<10&&n>=5)
    	{
    		num[maxn-1]++;
    		break;
    	}
    	else
    	{
    		i++;
    	}
    }
    return 0; 
}
