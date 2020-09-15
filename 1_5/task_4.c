#include <stdio.h>
#include <stdlib.h>

int main()
{
	char c = ' ';
	char c2;
	int sum = 0;;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (c != '.')
    {
        c2 = c;
        scanf("%c", &c);
        if (c != '.')
            sum += c - 48;
    }
    if ((sum % 3 == 0) && ((c2-3) % 5 == 0))
        printf("YES");
    else
        printf("NO");
	return 0;
}
