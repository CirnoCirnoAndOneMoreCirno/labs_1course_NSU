#include <stdio.h>

int main()
{
	int N, sum, num;
	sum = 0;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d ", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num);
		if ((num % 2) == 0)
			sum += num;
	}
	printf("%d", sum);
	return 0;
}
