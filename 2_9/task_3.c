#include <stdio.h>
#include <stdlib.h>
#define INF 1000000000

typedef struct point_s
{
    int x;
    int y;
}point;

typedef struct edge_s
{
    int a;
    int b;
    int len;
}edge;

int getSquareLen(int x1, int y1, int x2, int y2)
{
    return ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

int compareEdgesLen(const void *a, const void *b)
{
    return (((edge*)a)->len - ((edge*)b)->len);
}

int findMinFrame(edge *edges, edge *minFrame, int n, int m)
{
    qsort(edges, m, sizeof(edge), compareEdgesLen);
    int cnt = 0, newId, oldId;
    int *treeId = (int*) malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
        treeId[i] = i;
    for(int i = 0; i < m; i++)
    {
        if(treeId[edges[i].a] != treeId[edges[i].b])
        {

            minFrame[cnt].a = edges[i].a;
            minFrame[cnt].b = edges[i].b;
            minFrame[cnt].len = edges[i].len;
            oldId = treeId[edges[i].b];
            newId = treeId[edges[i].a];
            for(int j = 0; j < n; j++)
            {
                if (treeId[j] == oldId)
                {
                    treeId[j] = newId;
                }
            }

            cnt++;
        }
    }
    return cnt;
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m, a, b, index;
    scanf("%d", &n);

    point* pts = (point*) malloc(sizeof(point)*n);
    edge* edges = (edge*) malloc(sizeof(edge)*n*n);
    edge* minFrame = (edge*) malloc(sizeof(edge) * (n*n));

    for(int i = 0; i < n; i++)
        scanf("%d%d", &(pts[i].x), &(pts[i].y));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            index = i*n + j;
            edges[index].a = i;
            edges[index].b = j;
            edges[index].len = getSquareLen(pts[i].x, pts[i].y, pts[j].x, pts[j].y);
        }
    }

    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        --a; --b;
        edges[a*n + b].len = 0;
    }

    //sortEdges(edges, 0, n-1);
    int cnt = findMinFrame(edges, minFrame, n, n*n);

    for(int i = 0; i < cnt; i++)
        if (minFrame[i].len > 0)
            printf("%d %d\n", minFrame[i].a+1, minFrame[i].b+1);
    return 0;
}
