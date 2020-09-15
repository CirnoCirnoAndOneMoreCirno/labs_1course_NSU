#include <stdio.h>
#include <stdlib.h>
#define mINF -3147483649
#define pINF 3147483648

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void reverseArray(int *a, int len)
{
    for(int i = 0; i < len/2; i++)
        swap(&a[i], &a[len-i-1]);
}

int binSearch(long long *a, int x, int n)
{
    int l = 0, r = n-1;
    int index;
    while ((r - l) > 1)
    {
        index = (l + r)/2;
        if (a[index] <= x)
            l = index + 1;
        else
            r = index;
    }
    if (a[l] >= x)
        return l;
    if (a[r] >= x)
        return r;
    return r+1;
}

int findLIS(int *a, int *LIS, int n)
{
    long long int *dp = (long long int*) malloc((n+1) * sizeof(long long int));
    int *pos = (int*) malloc((n+1) * sizeof(int));
    int *prev = (int*) malloc(n * sizeof(int));
    int len = 0;
    pos[0] = -1;
    dp[0] = mINF;
    int j;
    for(int i = 1; i < n+1; i++)
        dp[i] = pINF;
    for(int i = 0; i < n; i++)
    {
        j = binSearch(dp, a[i], n);
        if ((dp[j-1] < a[i]) && (dp[j] >= a[i]))
        {
            dp[j] = a[i];
            pos[j] = i;
            prev[i] = pos[j-1];
            len = max(len, j);
        }
    }

    int p = pos[len], i = 0;
    while (p != -1)
    {
        LIS[i] = p;
        p = prev[p];
        i++;
    }
    reverseArray(LIS, len);
    return len;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, len;
    scanf("%d", &n);
    int *a = (int*) malloc(n * sizeof(int));
    int *LIS = (int*) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    len = findLIS(a, LIS, n);
    printf("%d\n", len);
    for(int i = 0; i < len; i++)
        printf("A[%d] = %d\n", LIS[i]+1, a[LIS[i]]);
    return 0;
}
