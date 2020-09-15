#include <stdio.h>

int main()
{
	char c = ' ';
	int k = 0;
	int isW = 0;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (c != '\n')
	{
		scanf("%c", &c);
		if ((c != '.') && !(isW) && (c != '\n'))
		{
			k++;
			isW = 1;
		}
		else if (c == '.')
			isW = 0;
	}
	printf("%d", k);
	return 0;
}
