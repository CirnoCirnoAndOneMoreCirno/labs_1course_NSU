#include <stdio.h>
#define N 5000

int main()
{
    int n, l, r, sumMax, sum, lMax, rMax, k;
    k = -1;
    sumMax = -5001;
    sum = 0;
    lMax = 0;
    rMax = 0;
    int a[N] = {0};
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sumMax = a[0];
    for (int i = 0; i < n; i++)
    {
        sum+=a[i];
        if (sum > sumMax)
        {
            sumMax = sum;
            lMax = k + 1;
            rMax = i;
        }
        if (sum < 0)
        {
           sum = 0;
           k = i;
        }
    }
    printf("%d %d %d", lMax, rMax, sumMax);
    return 0;
}
