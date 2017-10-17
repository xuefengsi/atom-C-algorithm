#include<iostream>
#define MaxSize 100
using namespace std;
typedef char ElemType;
typedef struct node
{
	ElemType data;
	struct node *next;
}LinkNode,*LinkStack;

//链表初始化，创建一个有头结点的链表 
LinkStack createLinkStack()
{
	LinkStack s;
	s = new LinkNode;
	s->next=NULL;
	return s;
}

int IsEmptyLinkStack(LinkStack s)
{
	//判断栈是否为空，若空返回1，否则返回0 
	return (s->next==NULL);
}
void push(ElemType a,LinkStack s)
{
	//将元素t压栈s 
	LinkStack t;
	t = new LinkNode;
	t->data=a;
	t->next=s->next;
	s->next=t;
}

char pop(LinkStack s)
{
	//删除并返回栈的栈顶元素 
	LinkStack firstV;
	int topElem;
	if(IsEmptyLinkStack(s))
	{
		cout<<"error"<<endl;
		return NULL;
	}
	else
	{
		firstV = s->next;
		s->next = firstV->next;
		topElem = firstV->data;
		delete firstV;
		return topElem;
	}
}

int main()
{
    char a[5]={'a','b','c','d','e'};
	int i;
    LinkStack p = createLinkStack();
	for(i=0;i<5;i++)
		push(a[i],p);
	for(i=0;i<5;i++) 
		cout<<pop(p);
	
}
