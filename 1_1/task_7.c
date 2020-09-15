#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
	int a, b, c;
	float D, x1, x2;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &a, &b, &c);
	if (a != 0)
	{
		D = b*b - 4 * a*c;
		if (D < 0)
			printf("NO");
		else if (D == 0)
		{
			printf("1 ", "\n");
			x1 = -b / (2.0*a);
			printf("%.5f", x1);
		}
		else
		{
			printf("2 \n");
			x1 = (-b + sqrt(D)) / (2.0*a);
			x2 = (-b - sqrt(D)) / (2.0*a);
			printf("%.5f %.5f", min(x2, x1), max(x2, x1));
		}
	}
	else if (b != 0)
	{
		printf("1 \n");
		x1 = (-1.0*c)/b;
		printf("%.5f", x1);
	}
	else
	{
		if (c != 0)
			printf("ERROR");
		else
			printf("MANY");
	}
	return 0;
}
