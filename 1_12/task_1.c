#include <stdio.h>

typedef struct SingleLinkedList_s
{
    double data;
    int next;
}SingleLinkedList;

void PrintSingleLinkedList (SingleLinkedList *list, int start)
{
    int i = start;
    while (i != -1)
    {
        printf("%.3lf\n", list[i].data);
        i = (list[i]).next;
    }
    return;
}

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, idStart;
    scanf("%d%d", &n, &idStart);
    SingleLinkedList *list = malloc(n * sizeof(SingleLinkedList));
    for(int i = 0; i < n; i++)
        scanf("%lf%d", &list[i].data, &list[i].next);
    PrintSingleLinkedList(list, idStart);
    return 0;
}
