#include <stdio.h>
#define N 1000

int main()
{
	int n, x, j;
	int a[N] = { 0 };
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i < n; i++)
	{
		x = a[i];
		j = i - 1;
		while ((j > -1) && (a[j] > x))
		{
			a[j + 1] = a[j];
			j--;

		}
		a[j + 1] = x;
	}
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}
