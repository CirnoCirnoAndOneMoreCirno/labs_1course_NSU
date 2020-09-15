#include <stdio.h>
#define N 100000

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k, sum;
	k = 1;
	scanf("%d", &n);
	int a[N] = {0};
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		for (int j = k - 1; j < n; j += k)
		{
			sum += a[j];
		}
		k++;
		printf("%d\n", sum);
	}
	return 0;
}
