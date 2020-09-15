#include <stdio.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    int ans = 0;
    while (n > 0)
    {
        ans*=10;
        ans+=n%10;
        n/=10;
    }
    printf("%d", ans);
    return 0;
}
