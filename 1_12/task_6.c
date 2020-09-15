#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SingleLinkedList_s
{
    int data;
    struct SingleLinkedList_s *next;
}SingleLinkedList;




int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    SingleLinkedList *head = NULL;
    SingleLinkedList *temp;
    int num, count = 0;

    while (scanf("%d", &num) != EOF)
    {
        SingleLinkedList *cell = malloc(sizeof(SingleLinkedList));
        cell->data = num;
        cell->next = head;
        head = cell;
    }

    while (head)
    {
        if ((head->data < 0) && ((head->data % 7) == 0))
        {
            count++;
        }
        temp = head->next;
        free(head);
        head = temp;
    }
    printf("%d", count);
    return 0;
}

