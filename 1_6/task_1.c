
#include <stdio.h>
#include <stdlib.h>
#define N 27

void NextTransp(char *a, int n)
{
    int m = n-1;
    int i = n-2;
    int c;
    while ((a[i] > a[i+1])&&(i > 0))
    {
        if (a[i] > a[m])
            m = i;
        i--;
    }
    for(int j = i; j < n; j++)
    {
        if ((a[j] > a[i]) && (a[j] < a[m]))
            m = j;
    }
    c = a[i];
    a[i] = a[m];
    a[m] = c;
    for(int j = i + 1; j <= ((n+i)/2); j++)
    {
        c = a[j];
        a[j] = a[n + i - j];
        a[n + i - j] = c;
    }
}

int main()
{
    char t[N], c;
    int n, d = 0;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; d < n ; i++)
    {
        scanf("%c", &c);
        if ((c != ' ') && (c != '\n'))
        {
            t[d] = c;
            d++;
        }
    }
    NextTransp(t, n);
    for (int i = 0; i < n; i++)
        printf("%c ", t[i]);
    return 0;
}
