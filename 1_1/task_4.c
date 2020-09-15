#include <stdio.h>

int main()
{
	int a, b;
	int k1, k2, k3, k4;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d", &a, &b);
	int quot = a / b;
    int res = a % b;
    k1 = quot;
    k2 = quot;
    k3 = quot;
    k4 = res;
    if (res!=0)
    {
        if (a<0)
            k1--;
        if (a>0)
            k2++;
    }
    if (res<0)
        k4+=b;
	printf("%d %d %d %d", k1, k2, k3, k4);
	return 0;
}
