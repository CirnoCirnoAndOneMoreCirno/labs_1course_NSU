#include <stdio.h>

int main()
{
	int a, b;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d", &a, &b);
	printf(((b >= 0) && (b < a)) ? "legal" : "out of bounds");
	return 0;
}
