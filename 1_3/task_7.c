#include <stdio.h>
#define N 1000000

int a[N];

int main()
{
    int n, x, l, r, i, ans;
    scanf("%d%d", &n, &x);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    l = 0;
    r = n - 1;
    i = 0;
    ans = -1;
    while (l <= r)
    {
        i = (l + r)/2;
        if (a[i] > x)
        {
            r = i - 1;
        }
        else if (a[i] < x)
        {
            l = i + 1;
        }
        else
        {
            ans = i;
            break;
        }
    }
    printf("%d", ans);
    return 0;
}
