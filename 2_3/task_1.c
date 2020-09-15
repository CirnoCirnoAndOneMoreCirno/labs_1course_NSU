#include <stdio.h>

typedef struct heap_s
{
    int length;
    int *data;
}heap;

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

heap *createHeap(int maxLength)
{
    heap *h = malloc(sizeof(heap));
    h->length = 0;
    h->data = malloc(maxLength * sizeof(int));
    return h;
}

void siftUp(heap *h, int index)
{
    if (h->data[index] < h->data[(index-1) / 2])
    {
        swap(&(h->data[index]), &(h->data[(index-1)/2]));
        siftUp(h, (index-1)/2);
    }
}

void siftDown(heap *h, int index)
{
    while (2*index + 1 < h->length)
    {
        int l = 2*index + 1;
        int r = 2*index + 2;
        int smallest = l;
        if ((r < h->length) && (h->data[r] < h->data[l]))
        {
            smallest = r;
        }
        if (h->data[index] > h->data[smallest])
            swap(&h->data[index], &h->data[smallest]);
        index = smallest;
    }
}

void pushToHeap(heap *h, int num)
{
    int i = h->length;
    h->data[i] = num;
    h->length++;
    siftUp(h, i);
}

int popFromHeap(heap *h)
{
    int num = h->data[0];
    h->data[0] = h->data[h->length - 1];
    h->length--;
    siftDown(h , 0);
    return num;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int q, num;
    char command[5];
    scanf("%d", &q);

    heap *h = createHeap(q);

    for(int ii = 0; ii < q; ii++)
    {
        scanf("%s ", command);
        if (command[1] == 'u')
        {
            scanf("%d", &num);
            pushToHeap(h, num);
        }
        else
        {
            if (h->length > 0)
                printf("%d\n", popFromHeap(h));
            else
                printf("Heap is empty\n");
        }
    }


    return 0;
}
