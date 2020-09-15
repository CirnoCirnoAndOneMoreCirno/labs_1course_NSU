#include <stdio.h>
#include <stdlib.h>

typedef struct DoubleLinkedList_s
{
    int data;
    struct DoubleLinkedList_s *next;
    struct DoubleLinkedList_s *prev;
}DoubleLinkedList;

void deleteNode (DoubleLinkedList *node, DoubleLinkedList *head, DoubleLinkedList *last)
{
    DoubleLinkedList *tmp = node;
    if (node == head)
        head = node->next;
    if (node == last)
        last = node->prev;
    (node->prev)->next = node->next;
    (node->next)->prev = node->prev;
    node = node->next;
    free(tmp);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k;
    DoubleLinkedList *head = malloc(sizeof(DoubleLinkedList)), *node = NULL, *prev2 = NULL, *last;
    head->data = 1;
    head->next = NULL;
    head->prev = NULL;
    prev2 = head;
    scanf("%d %d", &n, &k);
    if (n == 1)
    {
        printf("1");
        return 0;
    }
    for(int i = 2; i <=n; i++)
    {
        node = malloc(sizeof(DoubleLinkedList));
        node->data = i;
        node->prev = prev2;
        node->next = NULL;
        prev2->next = node;
        prev2 = node;
    }
    last = node;
    node->next = head;
    head->prev = last;
    node = head;
    while(head != last)
    {
        for(int i = 1; i < k; i++)
        {
            node = node->next;
        }
        DoubleLinkedList *tmp = node;
        if (node == head)
            head = node->next;
        if (node == last)
            last = node->prev;
        (node->prev)->next = node->next;
        (node->next)->prev = node->prev;
        node = node->next;
        free(tmp);
    }
    printf("%d", head->data);
    free(head);
    return 0;
