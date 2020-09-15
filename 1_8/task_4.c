#include <stdio.h>
#define N 11

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k, posX, posY, s, loopLenght, stepsBeforeLoop;
    int isLoop = 0;
    char map[N][N];
    scanf("%d%d%d", &n, &k, &posX);
    for(int i = 0; i < n; i++)
        scanf("%s", map[i]);
    posX--;
    posY = 0;
    s = 0;
    while ((posY < n) && (posY >= 0) && (posX < k) && (posX >= 0) && !(isLoop))
    {
        if (map[posY][posX] == 'N')
        {
            map[posY][posX] = s;
            posY--;
        }
        else if (map[posY][posX] == 'S')
        {
            map[posY][posX] = s;
            posY++;
        }
        else if (map[posY][posX] == 'E')
        {
            map[posY][posX] = s;
            posX++;
        }
        else if (map[posY][posX] == 'W')
        {
            map[posY][posX] = s;
            posX--;
        }
        else
        {
            isLoop = 1;
            stepsBeforeLoop = map[posY][posX];
            loopLenght = s - stepsBeforeLoop;
        }
        s++;
    }
    if (isLoop)
    {
        printf("%d step(s) before a loop of %d step(s)", stepsBeforeLoop, loopLenght);
    }
    else
        printf("%d step(s) to exit \n", s);
    return 0;
}

