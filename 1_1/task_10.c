#include <stdio.h>

int main()
{
	long int h, m, s, k;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d%d%d", &h, &m, &s, &k);
	s += k;
	m += s / 60;
	s %= 60;
	h += m / 60;
	m %= 60;
	h %= 24;
	printf("%d %d %d", h, m, s);
	return 0;
}
