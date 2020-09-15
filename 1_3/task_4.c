#include <stdio.h>
#define N 100000

int main()
{
    int n, count;
    count = 0;
    int a[N] = {0};
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < n; i++)
    {
        if (a[i] > -1001)
        {
            count++;
            for(int j = i + 1; j < n; j++)
            {
                if(a[i] == a[j])
                    a[j] = -1001;
            }
        }
    }
    printf("%d", count);
}
