#include <stdio.h>
#include <string.h>
#define N 300000

int a[N];

void Swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

int Patrition(int a[], int l, int r)
{
	int v = a[(l + r) / 2];
	int i = l;
	int j = r;
	while (i <= j)
	{
		while (a[i] < v)
			i++;
		while (a[j] > v)
			j--;
		if (i >= j)
			break;
		Swap(&a[i++], &a[j--]);
	}
	return j;
}

void Quicksort(int a[], int l, int r)
{
	int q;
	if (l < r)
	{
		q = Patrition(a, l, r);
		Quicksort(a, l, q);
		Quicksort(a, q + 1, r);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	long long sumOfMins = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	Quicksort(a, 0, n - 1);
	for (int i = 0; i < n - 1; i++)
		sumOfMins += (long long)(n - i - 1)*(long long)a[i];
	printf("%lld", sumOfMins);
	return 0;
}
