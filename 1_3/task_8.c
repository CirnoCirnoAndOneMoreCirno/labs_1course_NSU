#include <stdio.h>
#define N 100001

int main()
{
    int n, k, i, c;
    int l = 0;
    int a[N] ={0};
    scanf("%d%d", &n, &k);
    k = k % n;
    if (k>0)
        l = 1;
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < (n / 2); i++)
    {
        c = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = c;
    }
    for(i = 0; i < (k / 2); i++)
    {
        c = a[i];
        a[i] = a[k - i - 1];
        a[k - i - 1] = c;
    }
    for(i = k; i < ((n - k)/2 + k); i++)
    {
        c = a[i];
        a[i] = a[n - i - 1 + k];
        a[n - i - 1 + k] = c;
    }
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
