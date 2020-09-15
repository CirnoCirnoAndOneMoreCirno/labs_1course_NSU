#include <stdio.h>
#include <string.h>
#define N 200001

typedef struct SingleLinkedList_s
{
    char data[8];
    int next;
}SingleLinkedList;

void PrintSingleLinkedList (SingleLinkedList *list, int start)
{
    int i = start;
    while (i != -1)
    {
        printf("%s\n", list[i].data);
        i = (list[i]).next;
    }
    return;
}

void InsertInList(SingleLinkedList *list, int *n, int *start, int insertIndex, char newVal[])
{
    strcpy(list[*n].data, newVal);
    if (insertIndex == -1)
    {
        list[*n].next = *start;
        *start = *n;
    }
    else
    {
        list[*n].next= list[insertIndex].next;
        list[insertIndex].next = *n;
    }
    printf("%d\n", *n);
    (*n)++;
}

void RemoveFromList(SingleLinkedList *list, int *n, int *start, int index)
{
    if (index == -1)
    {
        printf("%s\n", list[*start].data);
        *start = list[*start].next;
    }
    else
    {
        printf("%s\n", list[list[index].next].data);
        list[index].next = list[list[index].next].next;
    }
}

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, n, idStart, operations, operationId, index;
    char newVal[8];
    scanf("%d", &t);
    for(int j = 0; j < t; j++)
    {
        scanf("%d%d%d", &n, &idStart, &operations);
        SingleLinkedList list[N];
        for(int i = 0; i < n; i++)
            scanf("%s %d", &list[i].data, &list[i].next);
        for(int i = 0; i < operations; i++)
        {
            scanf("%d%d", &operationId, &index);
            switch(operationId)
            {
                case 0:
                    {
                        scanf("%s", newVal);
                        InsertInList(list, &n, &idStart, index, newVal);
                        break;
                    }
                case 1:
                    {
                        RemoveFromList(list, &n, &idStart, index);
                        break;
                    }
                default:
                    break;
            }
        }
        printf("===\n");
        PrintSingleLinkedList(list, idStart);
        printf("===\n");
    }
    return 0;
