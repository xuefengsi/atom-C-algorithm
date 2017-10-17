
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
  LinkedNode *headList = new LinkedNode();
  headList->data = a[0];
  headList->next = NULL;
  for(int i=N-1;i>=1;i--)
  {
    LinkedNode *p = new LinkedNode();
    p->data = a[i];
    if(i!=N-1)
    {
      p->next = headList->next;
      headList->next = p;
    }
    else
    {
      p->next = headList;
      headList->next = p;
    }
  }
  return headList;
}
/*
bool IsLoop(LinkList headList)
{
  if(headList==NULL)
    return false;
  LinkList slow,fast;
  slow = headList->next;
  if(slow == NULL)
    return false;
  fast = slow->next;
  while(fast!=NULL && slow!=NULL)
  {
    if(fast == slow)
    {
      return true;
    }
    slow = slow->next;
    if(fast!=NULL)
    {
      fast =fast->next;
    }
  }
  return false;
}
*/
void IsLoop(LinkList headList)
{
  if(!headList||!headList->next)
    cout<<"No"<<endl;
  LinkList p,q;
  bool loop = false;
  p=q=headList->next;
  while(q&&q->next)
  {
    p=p->next;
    q=q->next->next;
    if(p==q)
    {
      loop=true;
      break;
    }
  }
  if(!loop)
    cout<<"No"<<endl;
  else
    cout<<"Yes"<<endl;
}
int main()
{
  char a[N] = {'a','b','c','d','e'};
  LinkedNode *list = createList(a);
  IsLoop(list);
}
