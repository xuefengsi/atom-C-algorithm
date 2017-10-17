/*
#include<iostream>
using namespace std;

int Binary_search(int a[], int n, int value, bool IsLeft)
{
	int left = 0;
	int right = n - 1;
	int last;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (a[mid] == value)
		{
			last = mid;
			if (IsLeft)
				right = mid - 1;
			else
				left = mid + 1;
		}
		else if (a[mid] > value)
			right = mid - 1;
		else if (a[mid] < value)
			left = mid + 1;
	}
	return last;
}
int main()
{
	int a[5] = {1,1,2,2,3};
	int left = Binary_search(a, 5, 1, true);
	int right = Binary_search(a, 5, 1, false);
	int count = right - left + 1;
	cout << count << endl;
}
*/

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

LinkStack creataListStack()
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
	char TopElem;
	if (IsEmptyLinkStack(S))
		return NULL;
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
	LinkStack S = creataListStack();
	for (int i = 0; i < 5; i++)
		push(S, a[i]);
	for (int i = 0; i < 5; i++)
		cout<<pop(S)<<" ";
	cout << endl;
}
*/
/*
#include<iostream>
#define n 4
using namespace std;
void n_queen(int a[], int i)
{
	if (i == n)
	{
		for (int j = 0; j < n; j++)
			cout << a[j] << " ";
		cout << endl;
	}
	else
	{
		for (int j = 0; j < n; j++)
		{
			int flag = 0;
			for (int cur = 0; cur < i; cur++)
			{
				if (j == a[cur] || j - i == a[cur] - cur || j + i == a[cur] + cur)
					flag = 1;
			}
			if (!flag)
			{
				a[i] = j;
				n_queen(a, i + 1);
			}
		}
	}
}
int main()
{
	int a[n] = { 0,0,0,0 };
	n_queen(a, 0);
}
*/
/*
#include<iostream>
using namespace std;
int *w;
int KNAP(int s, int n)
{
	if (s == 0)
		return 1;
	else if (s < 0 || s>0 && n < 1)
		return 0;
	else if (KNAP(s - w[n - 1], n - 1))
	{
		cout << n << ":" << w[n - 1] << endl;;
		return 1;
	}
	else
		return KNAP(s, n - 1);


}
int main()
{
	int n;
	cin >> n;
	w = new int[n];
	for (int i = 0; i < n; i++)
		cin >> w[i];
	int s;
	cin >> s;
	if (!KNAP(s, n))
		cout << "no" << endl;
}
*/
/*
#include<iostream>
using namespace std;
int main()
{
	int test,i,l=0;
	cin >> test;
	int *result = new int[test];
	while (test--)
	{
		int m;
		int count = 0;
		cin >> m;
		int *a = new int[m];
		for (i = 0; i < m; i++)
			cin >> a[i];
		for (i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				for (int k = 0; k < m; k++)
				{
					if (a[i] + a[j] == a[k])
						count++;
				}
			}
		}
		result[l] = count;
		l++;
		delete[]a;
	}
	for (i = 0; i < l; i++)
		cout << result[i] << endl;
	delete[]result;
}
*/
/*
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int test,i,k=0,num[50],h=0;
	char s[50],result[50][50];
	cin >> test;
	while (test--)
	{
		cin >> s;
		int len = strlen(s);
		int count = 0,j=0;
		for (i = 0; i < len; i++)
		{
			if (s[i] == '1')
			{
				count++;
				result[k][j] = s[i];
				j++;
				if (count == 5)
				{
					i++;
				}
			}
			else
			{
				result[k][j] = s[i];
				j++;
				count = 0;
			}
		}
		num[h]=j;
		h++;
		k++;
	}
	for (i = 0; i < k; i++)
	{
		for (int m = 0; m <num[i]; m++)
		{
			cout << result[i][m];
		}
		cout << endl;
	}
}
*/
/*
#include<iostream>
using namespace std;
int main()
{
	int test,k=0;
	cin >> test;
	int *result = new int[test];
	while (test--)
	{
		int n, m,count=0;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			if (m%i == 0 && m / i <= n)
				count++;
		}
		result[k] = count;
		k++;
	}
	for (int i = 0; i < k; i++)
		cout << result[i] << endl;
	delete []result;
}

*/
#include<iostream>
using namespace std;
int main()
{
	int test,h=0;
	cin >> test;
	int *result = new int[test];
	while (test--)
	{
		int n;
		cin >> n;
		int *a = new int[n];
		int *b = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			b[i] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			b[a[i]] += 1;
		}
		int max = 0;
		for (int i = 1; i < n; i++)
		{
			if (b[i] > b[max])
				max = i;
		}
		result[h] = max;
		h++;
		delete[]a;
		delete[]b;
	}
	for (int j = 0; j < h; j++)
		cout << result[j] << endl;
	delete[]result;
}




















































































