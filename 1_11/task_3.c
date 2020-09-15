#include <stdio.h>
#include <string.h>
#define N 1000001

int a[N];

void Swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void Sift(int mas[], int i, int n)
{
    int r;
    while (2 * i <= n)
    {
        r = 2 * i;
        if ((r + 1 <= n) && (mas[r] < mas[r+1]))
            r++;
        if (mas[i] < mas[r])
        {
            Swap(&a[i], &a[r]);
            i = r;
        }
        else
            break;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    if (n == 1)
    {
        printf("%d", a[1]);
    }
    else
    {
        i = n / 2;
        Sift(a, i, n);
        while (i >= 1)
        {
            Sift(a, i, n);
            i--;
        }
        i = n;
        while (i > 1)
        {
            Swap(&a[1], &a[i]);
            i--;
            Sift(a, 1, i);
        }
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", a[i]);
        }
    }
    return 0;
}

