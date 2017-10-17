#include<iostream>
#define MaxSize 100
using namespace std;

typedef int ElemType;
typedef struct 
{
	ElemType *base;
	int front;
	int rear;
}SqQuene;

void InitQuene(SqQuene *Q)
{
	Q->base = malloc(MaxSize*sizeof(ElemType));
	if(!Q->base)
		exit(OVERFLOW);
	Q->front=Q->rear=0;
}

int QueneLen(SqQuene Q)
{
	return (Q.rear-Q.front+MaxSize%MaxSize);
}

Status EnQuene(SqQuene *Q,ElemType e)
{
	
}
