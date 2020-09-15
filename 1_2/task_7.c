#include <stdio.h>

int main()
{
	int n, num;
	int min = 10001;
	int max = -10001;
	int numMin, numMax;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d ", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		if (num>max)
		{
			max = num;
			numMax = i + 1;
		}
		if (num < min)
		{
			min = num;
			numMin = i + 1;
		}
	}
	printf("%d %d %d %d", min, numMin, max, numMax);
	return 0;
}
