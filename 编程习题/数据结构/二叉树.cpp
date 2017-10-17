#include<iostream>
using namespace std;
typedef struct node
{
  char data;
  struct node *lchild,*rchild;
}Node,*PNode;
PNode CreateBiTree(PNode root);
//void PreOrder(PNode* &T);
int main()
{
  PNode root = NULL;
  root = CreateBiTree(root);
  cout<<root->data;
}

PNode CreateBiTree(PNode root)
{
  char ch;
  cin>>ch;
  if(ch == '#')
  {
    root=NULL;
    return root;
  }
  else
  {
    root = new Node;
    root->data = ch;
    root->lchild = CreateBiTree(root->lchild);
    root->rchild = CreateBiTree(root->rchild);
  }
  cout<<root->data;
  return root;
}
/*
void PreOrder(BiTNode* &T)
{
  if(T)
  {
    cout<<T->data;
    PreOrder(T->lchild);
    PreOrder(T->rchild);
  }
  else
    cout<<" ";
}
*/
