#include <stdio.h>
#include <stdlib.h>
#define N 10000

typedef struct list_s
{
    int data;
    struct list_s *next;
}list;

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

int dfs(int v, list **listOfAdjacency, int* used, int *newOrder, int *l, int *cycle)
{

    used[v] = 1; //красим вершимну в серый
    while (listOfAdjacency[v] != NULL)
    {
        if (used[listOfAdjacency[v]->data] == 0)
        {
            dfs(listOfAdjacency[v]->data, listOfAdjacency, used, newOrder, l, cycle);
        }
        else if (used[listOfAdjacency[v]->data] == 1) //зашли в серую вершину => есть цикл
            *cycle = 1;
        listOfAdjacency[v] = listOfAdjacency[v]->next;
    }
    used[v] = 2; //красим вершину в черный
    newOrder[(*l)] = v+1;
    (*l)++;
}

swap (int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void reverseArray(int *arr, int n)
{
    for(int i = 0; i < n/2; i++)
    {
        swap(&arr[i], &arr[n - i - 1]);
    }
}

int topologicalSort(list **listOfAdjacency, int *newOrder, int n)
{
    int cycle = 0;
    int len = 0;
    int used[N] = {0};
    for(int i = 0; i < n; i++)
    {
        if(!used[i])
            dfs(i, listOfAdjacency, used, newOrder, &len, &cycle);
    }
    reverseArray(newOrder, n);
    if(!cycle)
        return 1;
    return 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int countOfVertex, edges, a, b;
    scanf("%d%d", &countOfVertex, &edges);
    list **listOfAdjacency = (list**) malloc(countOfVertex*sizeof(list*));
    int order[N] = {0};
    int ans[N] = {0};
    for(int i = 0; i < countOfVertex; i++)
        listOfAdjacency[i] = NULL;
    for(int i = 0; i < edges; i++)
    {
        scanf("%d%d", &a, &b);
        --a;
        --b;
        listOfAdjacency[a] = addToList(listOfAdjacency[a], b);
    }
   if(topologicalSort(listOfAdjacency, order, countOfVertex))
    {
        for(int i = 0; i < countOfVertex; i++)
            ans[order[i] - 1] = i+1;
        for(int i = 0; i < countOfVertex; i++)
            printf("%d ", ans[i]);
    }
    else
        printf("-1");
    return 0;
}

