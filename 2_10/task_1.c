#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF 1001
#define N 100

void findShortcuts(int matrix[N][N], int n)
{
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if (matrix[i][j] > (matrix[i][k] + matrix[k][j]))
                    matrix[i][j] =  matrix[i][k] + matrix[k][j];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, a, b, from, to, dist;
    int matrix[N][N];

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            matrix[i][j] = INF;
            if (i == j)
                matrix[i][j] = 0;
        }
    }
    scanf("%d%d", &from, &to);
    --from;
    --to;
    while(scanf("%d%d%d", &a, &b, &dist) != EOF)
    {
        --a;
        --b;
        matrix[a][b] = dist;
        matrix[b][a] = dist;
    }
    findShortcuts(matrix, n);
    if (matrix[from][to] != INF)
        printf("%d", matrix[from][to]);
    else
        printf("no");
    return 0;
}

