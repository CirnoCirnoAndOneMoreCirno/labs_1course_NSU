#include <stdio.h>

int main()
{
	float a, b, c;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%f%f%fn", &a, &b, &c);
	float ans = a*b*c;
	printf("%f", ans);
	return 0;
}
