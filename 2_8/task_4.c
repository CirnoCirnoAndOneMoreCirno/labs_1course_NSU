#include <stdio.h>
#include <stdlib.h>
#define N 1000


void fillTheRoom(char maze[N][N], int n, int i, int j)
{
    if ((i >= 0) && (i < n) && (j >=0) && (j < n) && (maze[i][j] == ' '))
    {
        maze[i][j] = '#';
        if (j+1 < n)
            fillTheRoom(maze, n, i, j+1);
        if (i+1 < n)
            fillTheRoom(maze, n, i+1, j);
        if (j-1 >= 0)
            fillTheRoom(maze, n, i, j-1);
        if (i-1 >= 0)
            fillTheRoom(maze, n, i-1, j);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, rooms = 0;
    char maze[N][N];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        gets(maze[i]);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if (maze[i][j] == ' ')
            {
                rooms++;
                fillTheRoom(maze, n, i, j);
            }
        }
    }
    printf("%d", rooms-1);
    return 0;
}

