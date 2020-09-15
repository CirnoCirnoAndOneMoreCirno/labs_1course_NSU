#include <stdio.h>
#include <stdlib.h>
#define N 31


int main()
{
	char str[N];
    int maxIndex = 0;
    char c = ' ';
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while (c != '.')
    {
        scanf("%c", &c);
        if (c != '.')
        {
            str[maxIndex] = c;
            maxIndex++;
        }
    }
    maxIndex--;
    if ((str[maxIndex] != 'r') || (str[maxIndex-1] != 'e'))
    {
        if (str[maxIndex] == 'e')
            maxIndex--;
        for(int i = 0; i <= maxIndex; i++)
        {
            printf("%c", str[i]);
        }
        printf("er");
    }
    else
    {
        maxIndex-=2;
        for(int i = 0; i <= maxIndex; i++)
        {
            printf("%c", str[i]);
        }
        printf("est");
    }

    return 0;
}
