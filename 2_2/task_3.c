#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007

int numberOfPartitions(int n)
{
    int **dp = (int**) malloc((n+1)*sizeof(int*));
    for(int i = 0; i <= n; i++)
    {
        dp[i] = (int*) malloc((n+1)*sizeof(int));
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++)
        dp[i][0] = 0;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if (j > i)
                dp[i][j] = dp[i][i];
            else
                dp[i][j] = (dp[i][j-1] + dp[i-j][j]) % MOD;
        }
    }
    int answer = dp[n][n];
    for(int i = 0; i <= n; i++)
        free(dp[i]);
    free(dp);
    return answer;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    printf("%d", numberOfPartitions(n));
    return 0;
}
