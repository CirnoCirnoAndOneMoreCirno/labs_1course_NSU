#include <stdio.h>
#include <stdlib.h>
#define N 5000
char matrix[N][N];
int topologicalSort(char adjacencyMatrix[N][N], int* newOrder, int n)
{
    int p = 0, i, j;
    int *countOfIncomingEdges = malloc(n * sizeof(int));
    for(i = 0; i < n; i++)
        countOfIncomingEdges[i] = 0;

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            if (adjacencyMatrix[i][j])
                countOfIncomingEdges[j]++;

    while (p < n)
    {

        i = 0;
        while ((i < n) && (countOfIncomingEdges[i] != 0))
            i++;
        if (i == n)
        {
            free(countOfIncomingEdges);
            return 0;
        }
        newOrder[p] = i+1;
        p++;
        countOfIncomingEdges[i] = -1;
        for(j = 0; j < n; j++)
        {
            if (adjacencyMatrix[i][j] == 1)
                countOfIncomingEdges[j]--;
            adjacencyMatrix[i][j] = 0;
        }
    }
    free(countOfIncomingEdges);
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

