#include <stdio.h>

int main()
{
	char c = ' ';
	char c1, c2;
	int k = 1;
	int d = 0;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%c", &c);
	if (c == 'p')
	{
		c1 = 'R';
		c2 = 'B';
	}
	if (c == 'g')
	{
		c1 = 'Y';
		c2 = 'B';
	}
	if (c == 'o')
	{
		c1 = 'R';
		c2 = 'Y';

	}
	while (c != ' ')
	{
		scanf("%c", &c);
	}
	while (d < 2)
	{
		scanf("%c", &c);
		if ((c == c1) || (c == c2))
		{
			d++;
			printf("%d ", k);
		}
		k++;
	}
	return 0;
}
