#include <stdio.h>
#define N 1000001

int a[N] = {0};

int main()
{
    int n, j, k;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for(int i = 2; i <= n; i++)
        a[i] = i;
    for(int i = 2; i <= n; i++)
    {
        if (a[i]>0)
        {
            k = i;
            j = 2;
            while ((j*k) <= n)
            {
                a[j*k] = 0;
                j++;
            }
        }

    }
    for(int i = 2; i <= n; i++)
        if (a[i] > 0)
            printf("%d ", a[i]);
    return 0;
}

