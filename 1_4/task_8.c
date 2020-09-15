#include <stdio.h>

void Swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

int Gcd (int a, int b)
{
	while (b != 0)
    {
		a %= b;
		Swap (&a, &b);
	}
	return a;
}

int main()
{
	int a, b, n;
	unsigned long long d, g;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a, &b);
		g = Gcd(a, b);
		d = (a / g)*b;
		printf("%lld \n", d);
	}
	return 0;
}
