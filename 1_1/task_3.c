#include <stdio.h>

int main()
{
	int a, b, c;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &a, &b, &c);
	int m = 0;
	if ((a <= b) && (a <= c))
		m = a;
	if ((b <= a) && (b <= c))
		m = b;
	if ((c <= a) && (c <= b))
		m = c;
	printf("%d", m);
}
