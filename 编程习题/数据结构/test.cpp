/*
#include<iostream>
#define N 5
using namespace std;
typedef char DataType;
typedef struct node
{
  DataType data;
  struct node *next;
}LinkedNode,*LinkList;

LinkList createList(DataType a[])
{
  LinkedNode *headList = new LinkedNode;
  headList->data = a[0];
  headList->next = NULL;
  for(int i=N-1;i>=1;i--)
  {
    LinkedNode *p = new LinkedNode;
    p->data = a[i];
    p->next = headList->next;
    headList->next = p;
  }
  return headList;
}

void printList(LinkList headList)
{
  if(headList==NULL)
    cout<<"error"<<endl;
  else
  {
    LinkedNode *p = headList;
    while(p!=NULL)
    {
      cout<<p->data<<" ";
      p = p->next;
    }
    cout<<endl;
  }
}

LinkList reverseList(LinkList headList)
{
  if(headList==NULL)
    return NULL;
  LinkList cur,reverseHead,temp;
  if(headList->next==NULL)
    return headList;
  else
  {
    cur = headList;
    temp = headList->next;
    reverseHead = reverseList(temp);
    temp->next = cur;
    cur->next = NULL;
  }
  return reverseHead;
}
int main()
{
  char a[N]={'a','b','c','d','e'};
  LinkedNode *list = createList(a);
  printList(list);
  LinkedNode *p = reverseList(list);
  printList(p);
}
*/
/*
#include<iostream>
using namespace std;
typedef char DataType;
typedef struct node
{
  DataType data;
  struct node *next;
}LinkNode,*LinkStack;

LinkStack createListStack()
{
  LinkStack S;
  S = new LinkNode;
  S->next = NULL;
  return S;
}

int IsEmPty(LinkStack S)
{
  return (S->next == NULL);
}

void push(LinkStack S,DataType e)
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
  char TopElem;
  if(IsEmPty(S))
  {
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
  char a[5] = {'a','b','c','d','e'};
  LinkStack S = createListStack();
  for(int i=0;i<5;i++)
    push(S,a[i]);
  for(int i=0;i<5;i++)
    cout<<pop(S)<<" ";
  cout<<endl;
}
*/
#include<iostream>
#define N 5
using namespace std;
typedef char DataType;
typedef struct node
{
  DataType data;
  struct node *next;
}LinkedNode,*LinkList;

LinkList createList(DataType a[])
{
  LinkedNode *headList = new LinkedNode;
  headList->data = a[0];
  headList->next = NULL;
  for(int i=N-1;i>=1;i--)
  {
    LinkedNode *p = new LinkedNode;
    p->data = a[i];
    p->next = headList->next;
    headList->next = p;
  }
  return headList;
}

void printList(LinkList headList)
{
  if(headList==NULL)
    cout<<"NULL"<<endl;
  else
  {
    LinkedNode *p = headList;
    while(p!=NULL)
    {
      cout<<p->data<<" ";
      p = p->next;
    }
    cout<<endl;
  }
}

LinkList reverseList(LinkList headList)
{
  if(headList==NULL)
    return NULL;
  LinkList cur,reverseHead,temp;
  if(headList->next==NULL)
    return headList;
  else
  {
    cur = headList;
    temp = headList->next;
    reverseHead = reverseList(temp);
    temp->next = cur;
    cur->next = NULL;
  }
  return reverseHead;
}

int main()
{
  char a[N] = {'a','b','c','d','e'};
  LinkedNode *list = createList(a);
  printList(list);
  LinkedNode *p = reverseList(list);
  printList(p);
}
