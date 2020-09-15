#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
	int k;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &k);
	k -= 1;
	float D;
	D = sqrt(1 + 8 * k);
	if ((int)D == D)
		printf("1");
	else
		printf("0");
	return 0;
}
