#include <stdio.h>

int GetStart(int n)
{
	int res = 1;
	while (res < (n / 3))
		res = res * 3 + 1;
	return res;
}

void Insert(int a[], int b, int step, int n)
{
	int i = b + step;
	int x, j;
	while (i < n)
	{
		x = a[i];
		j = i - step;
		while ((j >= b) && (a[j] > x))
		{
			a[j + step] = a[j];
			j = j - step;
		}
		a[j + step] = x;
		i += step;
	}
}

void ShellSort(int a[], int n)
{
	int i, j, step;
	int tmp;
	int start = GetStart(n);
	for (step = start; step > 0; step = (step - 1) / 3)
	{
		for (i = 0; i < step; i++)
		{
			Insert(a, i, step, n);
		}
	}
}

int a[1000000];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	ShellSort(a, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
