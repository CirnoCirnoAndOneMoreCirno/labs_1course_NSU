#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

void restoreAnswer(int **dp, int *ans, int *w, int i, int j, int index)
{
    if (dp[i][j] == 0)
        return;
    if (dp[i-1][j] == dp[i][j])
        restoreAnswer(dp, ans, w, i-1, j, index);
    else
    {
        ans[index] = i;
        if (j - w[i-1] > 0)
            restoreAnswer(dp, ans, w, i-1, j - w[i-1], index+1);
    }
}

int getCount(int *ans)
{
    int i = 0;
    while (ans[i] != -1)
        i++;
    return i;
}

int getWeight(int *things, int *weight, int thingsCount)
{
    int weightAns = 0;
    for(int i = 0; i < thingsCount; i++)
        weightAns += weight[things[i] - 1];
    return weightAns;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, w, countAns, weightAns;
    scanf("%d%d", &n, &w);

    int *weight = (int*) malloc(n * sizeof(int));
    int *cost = (int*) malloc(n * sizeof(int));

    int *things = (int*) malloc((n+1) * sizeof(int));
    for(int i = 0; i <= n; i++)
        things[i] = -1;

    for(int i = 0; i < n; i++)
        scanf("%d %d", &weight[i], &cost[i]);

    int **dp = (int**) malloc((n+1)*sizeof(int*));
    for(int i = 0; i <= n; i++)
        dp[i] = (int*) malloc((w+1)*sizeof(int));

    for(int i = 0; i <= w; i++)
        dp[0][i] = 0;
    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            if (j >= weight[i-1])
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - weight[i-1]] + cost[i-1]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    restoreAnswer(dp, things, weight, n, w, 0);
    countAns = getCount(things);
    weightAns = getWeight(things, weight, countAns);
    printf("%d %d %d \n", countAns, weightAns, dp[n][w]);
    for(int i = 0; i < countAns; i++)
        printf("%d ", things[i]);

    free(things);
    free(weight);
    free(cost);
    for(int i = 0; i <= n; i++)
        free(dp[i]);
    free(dp);

    return 0;
}
