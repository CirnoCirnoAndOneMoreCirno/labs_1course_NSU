#include <stdio.h>
#include <stdlib.h>
#define N 20

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    unsigned long long int totalCost, mask, maskOfMax = 0, wCur, cCur, maxWeight, weight[N] = {0}, cost[N] = {0}, cAns = 0;
    int n, ans[N],  countAns = 0;
    scanf("%d %llu", &n, &maxWeight);
    for(int i = 0; i < n; i++)
    {
        scanf("%llu %llu", &weight[i], &cost[i]);
    }
    for(unsigned long long int i = 1; i <= 1LL*(1<<n)-1; i++)
    {
        mask = i;
        wCur = 0;
        cCur = 0;
        int j = 0;
        while (mask > 0)
        {
            if (mask&1)
            {
                cCur += cost[j];
                wCur += weight[j];
            }
            j++;
            mask>>=1;

        }
        if ((wCur <= maxWeight) && (cCur > cAns))
        {
            maskOfMax = i;
            cAns = cCur;
        }

    }
    int  j = 1;
    while (maskOfMax > 0)
    {
        if (maskOfMax&1)
        {
            ans[countAns] = j;
            countAns++;
        }
        maskOfMax>>=1;
        j++;
    }
    printf("%llu %d\n", cAns, countAns);
    for(int i = 0; i < countAns; i++)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}

