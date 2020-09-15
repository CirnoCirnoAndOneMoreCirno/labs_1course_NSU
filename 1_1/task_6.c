#include <stdio.h>

int main()
{
	int x, y, z, s;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &x, &y, &z);
	if (x <= 0)
		s = -1;
	else if (y <= 0)
		s = -2;
	else if (z <= 0)
		s = -3;
	else
		s = 2 * (x*y + z*y + z*x);
	printf("%d", s);
	return 0;
}
