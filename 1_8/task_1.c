#include <stdio.h>
#define N 1002

double a[N][N];

int main()
{
	int q, n, k;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	for (int i = 0; i < N; i++)
	{
		a[i][0] = 1;
		a[i][i] = 1;
	}
	for (int i = 2; i < N; i++)
	{
		for (int j = 1; j <= i - 1; j++)
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}

	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d", &n, &k);
		printf("%.10g \n", a[n][k]);
	}
	return 0;
}

