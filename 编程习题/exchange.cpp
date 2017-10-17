#include<iostream>
#include<string.h>
using namespace std;
int CmpStr(char *strA,char *strB)
{
	int count=0,max=81;
	int NA=strlen(strA),N=strlen(strB)-strlen(strA);
	while(N>0)
	{
		for(int i=0;i<NA;i++)
		{
			if(strA[i]!=strB[i+N])
			{
				count++;
			}
		}
		if(max>count)
		{
			max=count;
			count=0;
		}
		N--;
	}
	return max;
} 
int main()
{
	char strA[81],strB[81];
	cin>>strA>>strB;
	cout<<CmpStr(strA,strB)<<endl;
	return 0;
}
