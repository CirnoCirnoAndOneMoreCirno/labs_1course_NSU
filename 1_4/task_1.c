#include <stdio.h>

int main()
{
	int a, b, d;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d", &a, &b);
	while ((a != 0) && (b != 0))
	{
		if (a >= b)
			a %= b;
		else
			b %= a;
	}
	if (a > b)
		d = a;
	else
		d = b;
	printf("%d", d);
	return 0;
}
