#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DoubleLinkedList_s
{
    int data;
    int next;
    int prev;
}DoubleLinkedList;

DoubleLinkedList list[200001];

void addNextTo(int index, int num, int n)
{
    printf("%d\n", n);

    n++;
    list[n].data = num;
    list[n].prev = index;
    list[n].next = list[index].next;
    int temp = list[index].next;
    list[temp].prev = n;
    list[index].next = n;
}

void addPrevTo(int index, int num, int n)
{
    printf("%d\n", n);

    n++;
    list[n].data = num;
    list[n].next = index;
    list[n].prev = list[index].prev;
    int temp = list[index].prev;
    list[temp].next = n;
    list[index].prev = n;
}

void deleteNode(int index)
{
    printf("%d\n", list[index].data);

    int temp = list[index].prev;
    list[temp].next = list[index].next;
    temp = list[index].next;
    list[temp].prev = list[index].prev;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, last, n, q, first, operationIndex, index, num;
    scanf("%d", &t);
    for(int ii = 0; ii < t; ii++)
    {
        scanf("%d%d%d%d", &n, &first, &last, &q);
        list[0].next = first + 1;
        list[0].prev = last + 1;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &list[i].data, &list[i].next, &list[i].prev);
            list[i].next++;
            list[i].prev++;
        }
        for (int i = 0; i < q; i++)
        {
            scanf("%d%d", &operationIndex, &index);
            index++;
            switch (operationIndex)
            {
                case 1:
                {
                    scanf("%d", &num);
                    addNextTo(index, num, n);
                    n++;
                    break;
                }
                case -1:
                {
                    scanf("%d", &num);
                    addPrevTo(index, num, n);
                    n++;
                    break;
                }
                case 0:
                {
                    deleteNode(index);
                    break;
                }
                default:
                {
                    break;
                }
            }
        }
        printf("===\n");
        for(int j = list[0].next; j != 0; j = list[j].next)
        {
            printf("%d\n", list[j].data);
        }
        printf("===\n");
    }
    return 0;
}

