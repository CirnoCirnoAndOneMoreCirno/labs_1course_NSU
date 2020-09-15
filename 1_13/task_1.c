#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SingleLinkedList_s
{
    int data;
    struct SingleLinkedList_s *next;
}SingleLinkedList;

void ClearList(SingleLinkedList *head)
{
    SingleLinkedList *temp;
    while (head)
    {
        temp = head->next;
        free(head);
        head = temp;
    }
}

void PrintList(SingleLinkedList *head)
{
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    SingleLinkedList *head = NULL, *nextByNext = NULL, *start = NULL, *last = NULL;
    int num;

    while (scanf("%d", &num) != EOF)
    {
        SingleLinkedList *cell = malloc(sizeof(SingleLinkedList));
        cell->data = num;
        cell->next = NULL;
        if (head)
        {
            last->next = cell;
            last = cell;
        }
        else
            head = cell;
            last = cell;
    }

    start = head;

    while (head)
    {
       if (head->next)
       {
           nextByNext = head->next->next;
           if (head->data == head->next->data)
           {
               free(head->next);
               head->next = nextByNext;
               continue;
           }
       }
       head = head->next;
    }

    PrintList(start);
    ClearList(start);
    return 0;
}
