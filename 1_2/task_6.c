#include <stdio.h>

int main()
{
	int n, num, neg, pos;
	pos = 0;
	neg = 0;
	double negProp, posProp, zeroProp;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d ", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		if (num>0)
			pos++;
		else if (num < 0)
			neg++;
	}
	posProp = (1.0*pos) / n;
	negProp = (1.0*neg) / n;
	zeroProp = (n - pos - neg) / (n*1.0);
	printf("%0.5lf %0.5lf %0.5lf", negProp, zeroProp, posProp);
	return 0;
}
