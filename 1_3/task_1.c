#include <stdio.h>
#define N 100
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, cnt;
	scanf("%d", &n);
	int a[N] = {0};
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
	{
		cnt = 0;
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
				cnt++;
		}
		printf("%d ", cnt);
	}
	return 0;
}
