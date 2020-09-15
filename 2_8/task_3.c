#include <stdio.h>
#include <stdlib.h>
#define N 100000

typedef struct list_s
{
    int data;
    struct list_s *next;
}list;

list *addToList(list *head, int num)
{
    list *cell = (list*) malloc(sizeof(list));
    cell->data = num;
    cell->next = head;
    head = cell;
    return head;
}

void dfs(int v, list **listOfAdjacency, int* used, int* countOfComp, int vertex, int *countOfUsed)
{
    used[v] = *countOfComp;
    (*countOfUsed)++;
    while (listOfAdjacency[v] != NULL)
    {
        if (!used[listOfAdjacency[v]->data])
        {
            dfs(listOfAdjacency[v]->data, listOfAdjacency, used, countOfComp, vertex, countOfUsed);
        }
        listOfAdjacency[v] = listOfAdjacency[v]->next;
    }
}

int getConnectiveComponents (int countOfVertex, list ** listOfAdjacency, int *used)
{
    int countOfUsed = 0, countOfComp = 0;
    while (countOfUsed != countOfVertex)
    {
        for(int i = 0; i < countOfVertex; i++)
        {
            if (!used[i])
            {
                countOfComp++;
                dfs(i, listOfAdjacency, used, &countOfComp, countOfVertex, &countOfUsed);
                break;
            }

        }
    }
    return countOfComp;
}



int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int countOfVertex, edges, a, b, countOfComp = 0;
    scanf("%d%d", &countOfVertex, &edges);
    list **listOfAdjacency = (list**) malloc(countOfVertex*sizeof(list*));
    int used[N] = {0};
    for(int i = 0; i < countOfVertex; i++)
        listOfAdjacency[i] = NULL;
    for(int i = 0; i < edges; i++)
    {
        scanf("%d%d", &a, &b);
        --a;
        --b;
        listOfAdjacency[a] = addToList(listOfAdjacency[a], b);
        listOfAdjacency[b] = addToList(listOfAdjacency[b], a);
    }
    countOfComp = getConnectiveComponents(countOfVertex, listOfAdjacency, used);
    printf("%d\n", countOfComp);
    for(int i = 0; i < countOfVertex; i++)
        printf("%d ", used[i]);
    return 0;
}
