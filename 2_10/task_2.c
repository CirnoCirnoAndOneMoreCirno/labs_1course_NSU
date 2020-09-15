#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF INT_MAX
#define N 300

void findShortcuts(int matrix[N][N], int n)
{
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if (1LL*matrix[i][j] > (1LL*matrix[i][k] + matrix[k][j]))
                    matrix[i][j] =  matrix[i][k] + matrix[k][j];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, a, b, from, to, time, m;
    int matrix[N][N];

    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            matrix[i][j] = INF;
            if (i == j)
                matrix[i][j] = 0;
        }
    }
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &a, &b, &time);
        --a;
        --b;
        if (time < matrix[a][b])
        {
            matrix[a][b] = time;
            matrix[b][a] = time;
        }
    }
    findShortcuts(matrix, n);

    int requests;
    scanf("%d", &requests);
    for(int i = 0; i < requests; i++)
    {
        scanf("%d%d", &from, &to);
        --from;
        --to;
        if (matrix[from][to] != INF)
            printf("%d\n", matrix[from][to]);
        else
            printf("no");
    }
    return 0;
}

