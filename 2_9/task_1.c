#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define N 200000

typedef struct list_s {
    int data;
    struct list* next;
}list;

typedef struct stack_s { list *top; } stack;

stack* createNewStack()
{
    stack* S;
    S = malloc(sizeof (stack));
    S->top = NULL;
    return S;
}

int popFromStack(stack *S)
{
    int a;
    list *p;
    p = S->top;
    if (p)
    {
        a = p->data;
        S->top = p->next;
        free(p);
        return a;
    }
    return 0;
}

void pushToStack(int a, stack *S)
{
    list *cell = malloc(sizeof(list));
    cell->data = a;
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

list *addToList(list *head, int num)
{
    list *temp;
    list *cell = malloc(sizeof(list));
    cell->data = num;
    cell->next = NULL;
    if (head)
    {
        temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = cell;
    }
    else
        head = cell;
    return head;
}

void bfs(int vertex, list ** listOfAdjacency, int *dist, int n)
{
    stack* q = createNewStack();
    int color[N] = {0};
    int actualVertex, u;
    for(int i = 0; i < n; i++)
        dist[i] = INT_MAX;
    dist[vertex] = 0;
    color[vertex] = 2;
    pushToStack(vertex, q);
    while (q->top)
    {
        actualVertex = popFromStack(q);
        while (listOfAdjacency[actualVertex])
        {
            u = listOfAdjacency[actualVertex]->data;
            if (!color[u])
            {
                color[u] = 1;
                dist[u] = dist[actualVertex] + 1;
                pushToStack(u, q);
            }
            color[u] = 2;
            listOfAdjacency[actualVertex] = listOfAdjacency[actualVertex]->next;
        }
    }
    for (int i = 0; i < n; i++)
        if (color[i] == 0)
            dist[i] = -1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int countOfVertex, edges, a, b;
    int distance[N] = {0};
    scanf("%d%d", &countOfVertex, &edges);
    list **listOfAdjacency = (list**) malloc(countOfVertex*sizeof(list*));
    for(int i = 0; i < countOfVertex; i++)
        listOfAdjacency[i] = NULL;
    for(int i = 0; i < edges; i++)
    {
        scanf("%d%d", &a, &b);
        --a;
        --b;
        listOfAdjacency[a] = addToList(listOfAdjacency[a], b);

    }
    bfs(0, listOfAdjacency, distance, countOfVertex);
    for(int i = 0; i < countOfVertex; i++)
        printf("%d\n", distance[i]);
    return 0;
}
