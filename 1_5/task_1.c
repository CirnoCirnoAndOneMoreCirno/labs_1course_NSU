#include <stdio.h>
#define N 301

int main()
{
	char c = "";
	int k = 0;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%c", &c);
	if (c == 'M')
		printf("1");
	else if (c == 'W')
		printf("3");
	else if (c == 'F')
		printf("5");
	else if (c == 'T')
	{
		scanf("%c", &c);
		if (c == 'u')
			printf("2");
		else
			printf("4");
	}
	else
	{
		scanf("%c", &c);
		if (c == 'a')
			printf("6");
		else
			printf("7");
	}
	return 0;
}
