#include <stdio.h>
#include <stdlib.h>
#define INF 1e9
#define N 101

typedef struct cord_s
{
    int x;
    int y;
}cord;

typedef struct list_s {
    cord data;
    struct list* next;
}list;

typedef struct queue_s { list *top; } queue;

queue* createNewQueue()
{
    queue* S;
    S = malloc(sizeof (queue));
    S->top = NULL;
    return S;
}

cord popFromQueue(queue *S)
{
    cord a;
    list *p;
    p = S->top;
    a = p->data;
    S->top = p->next;
    free(p);
    return a;
}

void pushToQueue(cord a, queue *S)
{
    list *cell = malloc(sizeof(list));
    (cell->data).x = a.x;
    (cell->data).y = a.y;
    cell->next = NULL;
        if (S->top)
        {
            list *temp = S->top;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = cell;
        }
        else
            S->top = cell;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char maze[N][N];
    int dist[N][N];
    cord c;
    int n, m, start1, start2, finish1, finish2;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", maze[i]);
        for(int j = 0; j < m; j++)
        {
            if (maze[i][j] == 'S')
            {
                start1 = i;
                start2 = j;
            }
            if (maze[i][j] == 'F')
            {
                finish1 = i;
                finish2 = j;
            }
            dist[i][j] = INF;
        }
    }
    dist[start1][start2] = 0;
    queue *q = createNewQueue();
    c.x = start1;
    c.y = start2;
    cord cordToPush;
    pushToQueue(c, q);
    while (q->top)
    {
        c = popFromQueue(q);
        if ((c.x+1 < n) && (maze[c.x+1][c.y] != 'X') && (dist[c.x + 1][c.y] == INF)  )
        {
            dist[c.x+1][c.y] = dist[c.x][c.y] + 1;
            cordToPush.x = c.x + 1;
            cordToPush.y = c.y;
            pushToQueue(cordToPush, q);
        }
        if ((c.x-1 >= 0) && (maze[c.x-1][c.y] != 'X')&& (dist[c.x - 1][c.y] == INF))
        {
            dist[c.x-1][c.y] = dist[c.x][c.y] + 1;
            cordToPush.x = c.x-1;
            cordToPush.y = c.y;
            pushToQueue(cordToPush, q);
        }
        if ((c.y+1 < m) && (maze[c.x][c.y + 1] != 'X')&& (dist[c.x][c.y + 1] == INF))
        {
            dist[c.x][c.y+1] = dist[c.x][c.y] + 1;
            cordToPush.x = c.x;
            cordToPush.y = c.y+1;
            pushToQueue(cordToPush, q);
        }
        if ((c.y-1 >= 0) && (maze[c.x][c.y - 1] != 'X')&& (dist[c.x][c.y - 1] == INF))
        {
            dist[c.x][c.y-1] = dist[c.x][c.y] + 1;
            cordToPush.x = c.x;
            cordToPush.y = c.y-1;
            pushToQueue(cordToPush, q);
        }
    }
    if (dist[finish1][finish2] != INF)
        printf("%d", dist[finish1][finish2]);
    else
        printf("-1");
    return 0;
}
