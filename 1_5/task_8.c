#include <stdio.h>
#include <stdlib.h>
#define N 5

int main()
{
	char c = ' ';
	char n[N];
	int sum = 0;
	int i = 0;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (c != '.')
    {
        scanf("%c", &c);
        if ((c >= 48) && (c <= 57))
        {
            n[i] = c;
            i++;
        }
        else
        {
            sum += atoi(n);
            for (int j = 0; j < i; j++)
            {
                n[j] = 0;
            }
            i = 0;
        }
    }

    printf("%d", sum);
	return 0;
}
