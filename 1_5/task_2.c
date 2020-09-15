#include <stdio.h>

int main()
{
	char c = "";
	int k = 0;
	int ans = 1;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (c != '.')
	{
		k++;
		scanf("%c", &c);
		if ((k == 2) && (c != 'A'))
			ans = 0;
	}
	k--;
	if (k != 3)
		ans = 0;
	if (ans)
		printf("FITS");
	else
		printf("DOES NOT FIT");
	return 0;
}
