#include <stdio.h>
#include <stdlib.h>
#define N 5000
char matrix[N][N];
int topologicalSort(char adjacencyMatrix[N][N], int* newOrder, int n)
{
    int p = 0, i, j;
    int isEmpty;
    while (p < n)
    {
        for(i = 0; i < n; i++)
        {
            isEmpty = 1;
            while ((i < n) && (adjacencyMatrix[i][i] == -1))
                    i++;
            if (i == n)
            {
                isEmpty = 0;
                break;
            }
            for(j = 0; (j < n) && (isEmpty); j++)
            {
                if (adjacencyMatrix[j][i] == 1)
                    isEmpty = 0;
            }
            if (isEmpty)
            {
                newOrder[p] = i+1;
                p++;
                for(j = 0; j < n; j++)
                {
                    if (adjacencyMatrix[i][j] != -1)
                        adjacencyMatrix[i][j] = 0;

                }
                adjacencyMatrix[i][i] = -1;
                break;
            }
        }
        if (!isEmpty)
        {
            return 0;
        }
    }
    return 1;
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int order[N] = {0};
    int n, m, a, b;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            matrix[i][j] = 0;

    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &b, &a);
        matrix[b-1][a-1] = 1;
    }
    if(topologicalSort(matrix, order, n))
    {
        for(int i = 0; i < n; i++)
            printf("%d ", order[i]);
    }
    else
        printf("bad course");
    return 0;
}
