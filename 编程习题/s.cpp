#include<stdio.h>
char fun(char x,char y)
{
	if(x)
	{
		return y;
	}
}
int main()
{
	int a='0',b='1',c='2';
	printf("%d\n",fun(fun(a,b),fun(b,c)));
} 
