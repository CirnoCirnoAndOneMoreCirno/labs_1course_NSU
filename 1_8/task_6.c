#include <stdio.h>
#define N 251

void WriteInSquare(int square[][N], int cords[][2], int d, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            square[i][j] = 0;

    for(int i = 0; i < d; i++)
        square[cords[i][0]][cords[i][1]] = 1;
}

int GetLetters (int square[][N], char cipher[][N], char ans[], int n, int idStart)
{
    int isRight = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (square[i][j])
            {
                ans[idStart] = cipher[i][j];
                if (ans[idStart] == 0)
                {
                    isRight = 0;
                    //printf("%d %d \n", i, j);
                }
                cipher[i][j] = 0;
                idStart++;
            }
        }
    }
    return isRight;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k, d, isCutted, isRight, c;
    int cordsOfCutted[N*N][2];
    int square[N][N];
    char ans[N*N + 1];
    char cipher[N][N];
    int idStart = 0;
    scanf("%d", &n);
    n*=2;
    d = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &isCutted);
            if (isCutted)
                {
                    cordsOfCutted[d][0] = i;
                    cordsOfCutted[d][1] = j;
                    d++;
                }
        }
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%s", cipher[i]);
    }
    WriteInSquare(square, cordsOfCutted, d, n);
    isRight = GetLetters(square, cipher, ans, n, idStart);
    idStart+=d;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < d; j++)
        {
            c = cordsOfCutted[j][0];
            cordsOfCutted[j][0] = cordsOfCutted[j][1];
            cordsOfCutted[j][1] = n - 1 - c;
        }
        WriteInSquare(square, cordsOfCutted, d, n);
        isRight = GetLetters(square, cipher, ans, n, idStart);
        idStart+=d;
    }
    if (isRight)
        printf("%s", ans);
    else
        printf("No");
    return 0;
}

