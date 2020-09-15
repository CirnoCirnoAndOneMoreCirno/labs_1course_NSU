#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF LLONG_MAX
#define negINF (LLONG_MIN/2 + 1)

typedef struct edge_s
{
    int a, b;
    long long int cost;
}edge;

void findShortcuts(edge *e, long long int *distance, int from, int n, int m)
{
    distance[from] = 0;
    int *parent = (int*) malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
        parent[i] = -1;
    int x;
    for(int i = 0; i < n; i++)
    {
        x = -1;
        for(int j = 0; j < m; j++)
        {
            if (distance[e[j].a] < INF)
            {
                if (distance[e[j].b] > distance[e[j].a] + e[j].cost)
                {
                    distance[e[j].b] = distance[e[j].a] + e[j].cost;
                    parent[e[j].b] = e[j].a;
                if (distance[e[j].b] < negINF)
                        distance[e[j].b] = negINF;
                    x = e[j].b;
                }
            }
        }
    }
    if (x != -1)
    {
        int y = x;
        for(int i = 0; i < n; i++)
            y = parent[y];
        int len = 0;

        for(int current = y; (current!=y)||(len<1); current = parent[current])
        {
            distance[current] = negINF;
            len++;
        }
    }
    for(;;)
    {
        int flag = 0;
        for(int j = 0; j < n; j++)
        {
            if ((distance[parent[j]] == negINF) && (distance[j] != negINF))
            {
                distance[j] = negINF;
                flag = 1;
            }
        }
        if (!flag)
            break;
    }
    for(int i = 0; i < n; i++)
    {
        x = -1;
        for(int j = 0; j < m; j++)
        {
            if (distance[e[j].a] < INF)
            {
                if (distance[e[j].b] > distance[e[j].a] + e[j].cost)
                {
                    distance[e[j].b] = distance[e[j].a] + e[j].cost;
                    parent[e[j].b] = e[j].a;
                if (distance[e[j].b] < negINF)
                        distance[e[j].b] = negINF;
                    x = e[j].b;
                }
            }
        }
    }
    free(parent);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, a, b, from, to, m;
    long long int cost;
    scanf("%d%d%d", &n, &m, &from);

    long long int *distance = (long long int*)malloc(sizeof(long long int) * n);
    edge* e = (edge*)malloc(sizeof(edge) * m);

    for(int i = 0; i < n; i++)
        distance[i] = INF;

    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%lld", &a, &b, &cost);
        --a;
        --b;
        e[i].a = a;
        e[i].b = b;
        e[i].cost = cost;
    }
    --from;
    findShortcuts(e, distance, from, n, m);
    for(to = 0; to < n; to++)
    {
        if (distance[to] <= negINF/2)
            printf("-\n");
        else if(distance[to] == INF)
            printf("*\n");
        else
            printf("%lld\n", distance[to]);
    }
    return 0;
}

