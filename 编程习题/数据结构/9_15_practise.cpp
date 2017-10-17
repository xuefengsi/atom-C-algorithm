#include<iostream>
using namespace std;

typedef char DataType;
typedef struct node
{
	DataType data;
	struct node *next;
}LinkNode,*LinkStack;

LinkStack createLinkStack()
{
	LinkStack S;
	S = new LinkNode;
	S->next = NULL;
	return S;
}

int IsEmptyLinkStack(LinkStack S)
{
	return (S->next == NULL);
}

void push(LinkStack S, DataType e)
{
	LinkStack t;
	t = new LinkNode;
	t->data = e;
	t->next = S->next;
	S->next = t;
}

char pop(LinkStack S)
{
	LinkStack firstV;
	int TopElem;
	if (IsEmptyLinkStack(S))
	{
		cout << "ERROR" << endl;
		return NULL;
	}
	else
	{
		firstV = S->next;
		S->next = firstV->next;
		TopElem = firstV->data;
		delete firstV;
		return TopElem;
	}
}

int main()
{
	char a[5] = { 'a','b','c','d','e' };
	LinkStack S = createLinkStack();
	for (int i = 0; i < 5; i++)
		push(S, a[i]);
	for (int i = 0; i < 5; i++)
		cout<<pop(S)<<" ";
}
