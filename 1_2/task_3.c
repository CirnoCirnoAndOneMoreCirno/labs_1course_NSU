#include <stdio.h>

int main()
{
	int N;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d ", &N);
	int isPrime = 1;
	for (int i = 2; i < N; i++)
	{
		if ((N%i) == 0)
			isPrime = 0;
	}
	if (N == 1)
		isPrime = 0;
	if (isPrime)
		printf("YES");
	else
		printf("NO");
	return 0;
}
