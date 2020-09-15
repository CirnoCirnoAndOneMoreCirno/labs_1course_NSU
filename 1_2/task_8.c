#include <stdio.h>

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, ans, d;
	ans = 0;
	double dif, minDif, num;
	minDif = 1.0;
	scanf("%d \n", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &num);
		if (num < 0)
			num = -1.0*num;
		d = (int)num;
		dif = num - d;
		if (dif < minDif)
		{
			minDif = dif;
			ans = i + 1;
		}
		dif = d + 1 - num;
		if (dif < minDif)
		{
			minDif = dif;
			ans = i + 1;
		}
	}
	printf("%d", ans);
	return 0;
}
