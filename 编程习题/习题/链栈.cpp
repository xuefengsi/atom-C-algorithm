#include<iostream>
#define MaxSize 100
using namespace std;
typedef char ElemType;
typedef struct node
{
	ElemType data;
	struct node *next;
}LinkNode,*LinkStack;

//�����ʼ��������һ����ͷ�������� 
LinkStack createLinkStack()
{
	LinkStack s;
	s = new LinkNode;
	s->next=NULL;
	return s;
}

int IsEmptyLinkStack(LinkStack s)
{
	//�ж�ջ�Ƿ�Ϊ�գ����շ���1�����򷵻�0 
	return (s->next==NULL);
}
void push(ElemType a,LinkStack s)
{
	//��Ԫ��tѹջs 
	LinkStack t;
	t = new LinkNode;
	t->data=a;
	t->next=s->next;
	s->next=t;
}

char pop(LinkStack s)
{
	//ɾ��������ջ��ջ��Ԫ�� 
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
