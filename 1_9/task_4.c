#include <stdio.h>
#define N 100000

int BinSearch(int a[], int x, int l, int r)
{
	int m;
	while (l<r)
	{
		m = (r + l) / 2;
		if (a[m] > x)
		{
			r = m;
		}
		else
		{
			l = m + 1;
		}
	}

	return l;
}

void InsertionSort(int a[], int n)
{
	int x, k;
	for (int i = 1; i < n; i++)
	{
		x = a[i];
		k = BinSearch(a, x, 0, i);
		for (int d = i; d > k; d--)
		{
			a[d] = a[d - 1];
		}
		a[k] = x;
	}
}

int main()
{
	FILE *input;
	FILE *output;
	input = fopen("input.txt", "r");
	output = fopen("output.txt", "w");
	int ans = 0;
	int isProg = 1;
	int n = 0;
	int a[N];
	while (fscanf(input, "%d", &a[n]) != -1)
		n++;
	InsertionSort(a, n);
	ans = a[1] - a[0];
	isProg = n > 1;
	for (int i = 1; i < n-1; i++)
	{
		if ((a[i + 1] - a[i]) != ans)
			isProg = 0;
	}
	if (isProg)
		fprintf(output, "%d", ans);
	else
		fprintf(output, "NO");
	fclose(input);
	fclose(output);
	return 0;
}
