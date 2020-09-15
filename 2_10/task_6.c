#include <stdio.h>
#include <stdlib.h>
#define N 13

typedef struct point_s {int x, y;} point;

int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

void swap(int *a, int *b)
{
    int c = *b;
    *b = *a;
    *a = c;
}

int triangleArea (point a, point b, point c)
{
    return ((b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y));
}

int intersectProjections(int a, int b, int c, int d)
{
    if (a > b)
        swap(&a, &b);
    if (c > d)
        swap(&c, &d);
    return max(a, c)  <= min(b, d);
}

int intersectSegments(point a1, point a2, point b1, point b2)
{
    return (
            (intersectProjections(a1.x, a2.x, b1.x, b2.x))
            && (intersectProjections(a1.y, a2.y, b1.y, b2.y))
            && (triangleArea(a1, a2, b1) * triangleArea(a1,a2,b2) <= 0)
            && (triangleArea(b1, b2, a1) * triangleArea(b1,b2,a2) <= 0));
}

void floyd(int matrix[N][N], int n)
{
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                matrix[i][j] = matrix[i][j] || (matrix[i][k] && matrix[k][j]);
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    point pts[N][2];
    int matrix[N][N];
    int n = -1;
    while (n != 0)
    {
        scanf("%d", &n);
        for(int i = 0; i < n ; i++)
        {
            for(int j = 0; j < n; j++)
                matrix[i][j] = 0;
            pts[i][0].x = 0; pts[i][0].y = 0; pts[i][1].x = 0; pts[i][1].y = 0;
        }
        for(int i = 0; i < n; i++)
            scanf("%d%d%d%d", &(pts[i][0].x), &(pts[i][0].y), &(pts[i][1].x), &(pts[i][1].y));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                matrix[i][j] = intersectSegments(pts[i][0], pts[i][1], pts[j][0], pts[j][1]);
                matrix[j][i] = matrix[i][j];
            }
            matrix[i][i] = 1;
        }
        floyd(matrix, n);
        int a, b;
        while (n != 0)
        {
            scanf("%d%d", &a, &b);
            if ((a == 0) && (b == 0))
                break;
            --a; --b;
            if (matrix[a][b])
                printf("CONNECTED\n");
            else
                printf("NOT CONNECTED\n");
        }
    }
    return 0;
}

