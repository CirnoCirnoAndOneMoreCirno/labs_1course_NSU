#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF INT_MAX
#define N 502

void doTransitiveClosure(char matrix[N][N], int n)
{
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if (((matrix[i][k] == '1') && (matrix[k][j] == '1')) || (i == j))
                    matrix[i][j] =  '1';
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    char matrix[N][N];

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", matrix[i]);
    }
    doTransitiveClosure(matrix, n);
    for(int i = 0; i < n; i++)
        printf("%s\n", matrix[i]);
    return 0;
}
