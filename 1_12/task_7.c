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
    SingleLinkedList *temp, *tail;
    int num, count = 0, sum = 0;

    while (scanf("%d", &num) != EOF)
    {
        SingleLinkedList *cell = malloc(sizeof(SingleLinkedList));
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
    }

    while (head)
    {
        sum+= head->data;
        count++;
        temp = head->next;
        free(head);
        head = temp;
    }
    printf("%d", sum/count);
    return 0;
}
