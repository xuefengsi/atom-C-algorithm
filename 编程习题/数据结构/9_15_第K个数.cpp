#include<iostream>
using namespace std;

void exchange(int &a, int &b)
{
	int t=a;
	a = b;
	b = t;
}
int partition(int a[], int left, int right)
{
	int i = left - 1;
	int j;
	if(a[left]>a[right])
		exchange(a[left],a[right]);
	int x = a[right];
	for (j = 1; j < right; j++)
	{
		if (a[j] > x)
		{
			exchange(a[j], a[i+1]);
			i++;
		}
	}
	exchange(a[right], a[i + 1]);
	return (i+1);
}

int k_element(int a[], int left, int right, int k)
{
	if (left >= right)
		return a[left];
	int q = partition(a, left, right);
	if (q == k - 1)
		return a[q];
	else if (q >= k)
		return k_element(a, left, q - 1, k);
	else if (q < k)
		return k_element(a, q + 1, right, k - (q + 1));
}
int main()
{
	int len;
	int a[100],b[100],j=0;
	cin >> len;
	for (int i = 0; i < len; i++)
		cin >> a[i];
		for(int i=0;i<len;i++)
		{
			if(a[i]!=a[i+1])
			{
				b[j++]=a[i];
			}
			else
			{
				b[j++]=a[i];
				i++;
			}
		}
	int k;
	cin >> k;
	cout << k_element(b, 0, len - 1, len-k+2) << endl;
}
