#include <stdio.h>
#include <stdlib.h>

typedef struct SingleLinkedList_s
{
    int data;
    struct SingleLinkedList_s *next;
}SingleLinkedList;

void deleteNode(SingleLinkedList *prevNode)
{
    SingleLinkedList *nodeToDelete = prevNode->next;
    prevNode->next = nodeToDelete->next;
    free(nodeToDelete);
}

SingleLinkedList *deleteHead(SingleLinkedList *head)
{
    SingleLinkedList *temp = head;
    head = head->next;
    free(temp);
    return head;
}

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

SingleLinkedList *deletePrev(SingleLinkedList *head, int x)
{
    SingleLinkedList *cur = head;
    SingleLinkedList *prev = NULL;
    while (cur->next != NULL)
    {
        if(cur->next->data == x)
        {
            if (prev == NULL)
            {
                cur = cur->next;
                head = deleteHead(head);
                prev = head;
            }
            else
            {
                deleteNode(prev);
                cur = prev->next;
            }
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int x, num;
    SingleLinkedList *head = NULL;
    scanf("%d", &x);
    while (scanf("%d", &num) != EOF)
    {
        SingleLinkedList *cell = malloc(sizeof(SingleLinkedList));
        cell->data = num;
        cell->next = head;
        head = cell;
    }

    head = deletePrev(head, x);
    PrintList(head);
    ClearList(head);
    return 0;
}
