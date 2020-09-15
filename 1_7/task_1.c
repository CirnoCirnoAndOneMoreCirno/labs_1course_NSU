#include <stdio.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, s = 1;
    int num = 0;
    char c;
    scanf("%d", &n);
    scanf("%c", &c);
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &c);
        num += s*(c - '0');
        s*=2;
        if (s == 256)
        {
            s = 1;
            printf("%d ", num);
            num = 0;
        }
    }
    if (s > 1)
        printf("%d", num);
    return 0;
}

