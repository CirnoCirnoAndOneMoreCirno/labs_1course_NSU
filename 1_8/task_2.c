#include <stdio.h>
#define N 10


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m, s;
	int a[N][N];
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	}

	for (int i = 0; i < n; i++)
	{
		s = 0;
		for (int j = 0; j < m; j++)
		{
			s += a[i][j];
			if ((a[i][j] == 0) && (s != 0))
			{
				printf("%d ", s);
				s = 0;
			}
		}
		if (s != 0)
			printf("%d", s);
		printf("\n");
	}

	for (int i = 0; i < m; i++)
	{
		s = 0;
		for (int j = 0; j < n; j++)
		{
			s += a[j][i];
			if ((a[j][i] == 0) && (s != 0))
			{
				printf("%d ", s);
				s = 0;
			}
		}
		if (s != 0)
			printf("%d", s);
		printf("\n");
	}
	return 0;
}

