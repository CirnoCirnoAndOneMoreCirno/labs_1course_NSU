#include <stdio.h>
#define N 1000000

float a[N] = {0.0};

int main()
{
    int n, x, l, r, i, ans;
    scanf("%d%d", &n, &x);
    for(i = 0; i < n; i++)
        scanf("%f", &a[i]);
    l = 0;
    r = n - 1;
    i = (l + r) / 2;
    while ((r - l) > 1)
    {
        i = (l + r) / 2;
        if (a[i] >= x)
        {
            r = i;
        }
        else if (a[i] <= x)
        {
            l = i;
        }
        /**else
        {
          r = i;
          l = i;
        }**/ // !! 5 0
          //0.0 0.0 0.0 0.0 0.0

    }
    if ((x - a[l]) <= (a[r] - x))
    {
        ans = l;
    }
    else
    {
        ans = r;
    }
    printf("%d", ans);
    return 0;
}
