
#include<iostream>
#define N 6
using namespace std;
typedef int DataType;
typedef struct node
{
	DataType data;
	struct node *next;
}LinkedNode,*LinkList;

LinkList CreateList(DataType a[])
{
	LinkedNode *ListHead = new LinkedNode();
	ListHead->data=a[0];
	ListHead->next=NULL;
	for(int i=N-1;i>=1;i--)
	{
		LinkedNode *p = new LinkedNode();
		p->data=a[i];
		p->next=ListHead->next;
		ListHead->next=p;
	}
	return ListHead;
}

void printList(LinkList ListHead)
{
	if(ListHead==NULL)
		cout<<"error"<<endl;
	else
	{
		LinkedNode *p = ListHead;
		while(p!=NULL)
		{
			cout<<p->data<<" ";
			p=p->next;
		}
		cout<<endl;
	}
}
LinkList reverseList(LinkList L)
{
	if(L==NULL)
		return NULL;
    LinkList cur,reverseHead,temp;
    if(L->next==NULL)
    	return L;
    else
    {
    	cur = L;
    	temp = L->next;
    	reverseHead = reverseList(temp);
    	temp->next = cur;
    	cur->next = NULL;
    }
    return reverseHead;
} 
int main()
{
	int a[N]={1,2,3,4,5,6};
	LinkedNode *list = CreateList(a);
	printList(list);
	LinkedNode *p = reverseList(list);
	printList(p);
}
