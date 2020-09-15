#include <stdio.h>
#define N 10000

void GetPrimes(int *a, int n)
{
    for (int i = 0; i < n; i++)
        a[i] = 1;
    a[0] = 0;
    a[1] = 0;
    for(int i = 2; i < n; i++)
    {
        if (a[i])
        {
            for(int j =i*i; j < n; j+=i)
                a[j] = 0;
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, d, isFit, num, r;
    int a[N];
    GetPrimes(a, N);
    scanf("%d", &n);
    for (int ii = 0; ii < n; ii++)
    {
        d = 2;
        isFit = 0;
        scanf("%d", &num);
        while ((num / d) > N)
            d <<= 1;
        while (!isFit)
        {
            r = num / d;
            if  (a[r])
                isFit = 1;
            else
                d <<= 1;
        }
        printf("%d \n", d);
    }
    return 0;
}
