// 单链表.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#define N 5
using namespace std;
typedef char DataType;
typedef struct node
{
	DataType data;
	struct node *next;
}LinkedNode, *LinkList;

LinkList createList(DataType a[])
{
	LinkedNode *headList = new LinkedNode();
	headList->data = a[0];
	headList->next = NULL;
	for (int i = N - 1; i >= 1; i--)
	{
		LinkedNode *p = new LinkedNode();
		p->data = a[i];
		p->next = headList->next;
		headList->next = p;
	}
	return headList;
}

void printList(LinkList headList)
{
	if (headList == NULL)
		cout << "error" << endl;
	else
	{
		LinkedNode *p = headList;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
}

LinkList reverseList(LinkList headList)
{
	if (headList == NULL)
		return NULL;
	LinkList cur, reverseHead, temp;
	if (headList->next == NULL)
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
	char a[N] = { 'a','b','c','d','e' };
	LinkedNode *list = createList(a);
	printList(list);
	LinkedNode *p = reverseList(list);
	printList(p);
    return 0;
}

