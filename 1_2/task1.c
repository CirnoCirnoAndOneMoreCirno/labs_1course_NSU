#include <stdio.h>

int main()
{
	int N, sum;
	sum = 0;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d ", &N);
	for (int i = 1; i <= N; i++)
		sum += i;
	printf("%d", sum);
	return 0;
}
