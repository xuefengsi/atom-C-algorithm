//���ƺ͵ݹ�Ĳ���
//�������Ƕ���ŵ���ƣ�����ǰ�漸���õ������
//�ݹ��Ǵ��»�С�����纺ŵ������
//���һ��������Ե���Ҳ���Եݹ飬���õ��ƣ���Ϊ��Ч�ʱȵݹ��


//����
//1.�ֽ� 2.��� 3.�ϲ�

//̰��
//���㷽��
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
			break;//�ҵ���nС�������� 
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
