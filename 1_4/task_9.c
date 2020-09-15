#include <stdio.h>
#define N 303

int main()
{
	int y[N] = { 0 };
	int x[N] = { 0 };
	int isFunction = 1;
	int isEverewhereDefine = 1;
	int isInjection = 1;
	int isSurjection = 1;
	int x1, y1, n, m;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x1, &y1);
		if (y[x1] != 0)
			isFunction = 0;
		y[x1] = 1;
		if (x[y1] != 0)
			isInjection = 0;
		x[y1] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		if (y[i] == 0)
			isEverewhereDefine = 0;
		if (x[i] == 0)
			isSurjection = 0;
	}

	if (isFunction)
	{
		printf("1 ");
		if (isEverewhereDefine)
			printf("2 ");
		if (isInjection)
			printf("3 ");
		if (isSurjection)
			printf("4 ");
		if (isSurjection && isInjection)
			printf("5 ");
	}
	else
	{
		printf("0");
	}
	return 0;
}
