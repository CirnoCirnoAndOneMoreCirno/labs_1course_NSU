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

void sift(heap *h, int len, int index)
{
    int largest = index;

    int l = 2*index+1;
    int r = 2*index+2;

    if ((l < len) && (h->data[l] > h->data[largest]))
        largest = l;

    if ((r < len) && (h->data[r] > h->data[largest]))
        largest = r;
    if(largest != index)
    {
        swap(&h->data[largest], &h->data[index]);
        sift(h, len, largest);
    }
}

void heapSort(heap *h)
{
    int len = h->length;
    for (int i = len / 2 - 1; i >= 0; i--) {
        sift(h, len, i);
    }

    for (int i = len - 1; i >= 0; i--) {
        swap(&h->data[0], &h->data[i]);
        sift(h, i, 0);
    }
}

int main()
{
    FILE *in = fopen("input.bin", "rb");
    FILE *out = fopen("output.bin", "wb");

    int len;
    fread(&len, sizeof(int), 1, in);
    heap *mas = createHeap(len);
    fread(mas->data, sizeof(int), len, in);
    mas->length = len;
    heapSort(mas);
    fwrite(mas->data, sizeof(int), len, out);

    free(mas->data);
    free(mas);
    return 0;
}
