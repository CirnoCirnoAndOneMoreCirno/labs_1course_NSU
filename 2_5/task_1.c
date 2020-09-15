#include <stdio.h>
#include <stdlib.h>
int **table;

void resetQueen(int str, int col, int n, int m)
{
    for(int i = 0; i < m; i++)
        table[i][col]--;
    for(int i = 0; i < n; i++)
        table[str][i]--;
    int j = col + 1;
    for(int i = str+1; (i < m) && (j < n); i++, j++)
        table[i][j]--;
    j = col - 1;
    for(int i = str+1; (i < m) && (j >= 0); i++, j--)
        table[i][j]--;
    table[str][col] = 0;
}

void setQueen(int str, int col, int n, int m)
{
    for(int i = 0; i < m; i++)
        table[i][col]++;
    for(int i = 0; i < n; i++)
        table[str][i]++;
    int j = col + 1;
    for(int i = str+1; (i < m) && (j < n); i++, j++)
        table[i][j]++;
    j = col - 1;
    for(int i = str+1; (i < m) && (j >= 0); i++, j--)
        table[i][j]++;
    table[str][col] = -1;
}

int tryQueen(int i, int n, int m)
{
    int result = 0;
    for(int j = 0; j < n; j++)
    {
        if (table[i][j] == 0)
        {
            setQueen(i, j, n, m);
            if (i == m-1)
                result = 1;
            else
            {
                result = tryQueen(i+1, n, m);
                if (result == 0)
                {
                    resetQueen(i, j, n, m);
                }
            }
        }
        if (result)
            break;
    }
    return result;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int m, n;
    scanf("%d%d", &m, &n);
    table = (int**) malloc(m*sizeof(int*));
    char s[13];
    for(int i = 0; i < m; i++)
    {
        table[i] = (int*) malloc(n*sizeof(int));
        scanf("%s\n", s);
        for(int j = 0; j < n; j++)
        {
            if (s[j] == '.')
                table[i][j] = 1;
            else
                table[i][j] = 0;
        }
    }
    int isPossible = tryQueen(0, n, m);
    if (!isPossible)
        printf("NO");
    else
    {
        printf("YES\n");
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if (table[i][j] == -1)
                    printf("X");
                else
                    printf(".");
            }
            printf("\n");
        }
    }
    return 0;
}
