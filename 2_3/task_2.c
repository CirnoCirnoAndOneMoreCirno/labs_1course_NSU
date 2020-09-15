#include <stdio.h>
#include <stdlib.h>

typedef struct deque_s
{
    int first;
    int actualSize;
    int *buffer;
    int length;
}deque;

deque *createDeque(int length)
{
    deque *b = malloc(sizeof(deque));
    b->buffer = malloc(length * sizeof(int));
    b->length = length;
    b->first = -1;
    b->actualSize = 0;
    return b;
}

int getFromFront(deque *buff)
{
    int index = (buff->first + buff->actualSize - 1) % buff->length;
    return buff->buffer[index];
}

int popFromFront(deque *buff)
{
    /**if (buff->actualSize == 0)
        return ERROR_DEQUE_IS_EMPTY;**/
    int x = getFromFront(buff);
    buff->actualSize--;
    return x;
}

void pushToFront(deque *buff, int x)
{

    while ((buff->actualSize > 0)&&(getFromFront(buff) < x))
        popFromFront(buff);
    buff->actualSize++;
    if (buff->first == -1)
        buff->first = 0;
    int index = (buff->first + buff->actualSize - 1) % buff->length;
    buff->buffer[index] = x;
}

int getFromBack(deque *buff)
{
    int index = buff->first;
    return buff->buffer[index];
}

int popFromBack(deque *buff)
{
    /**if (buff->actualSize == 0)
        return ERROR_DEQUE_IS_EMPTY;**/
    int x = getFromBack(buff);
    buff->first++;
    buff->actualSize--;
    if (buff->first >= buff->length)
        buff->first = 0;
    return x;
}

void pushToBack(deque *buff, int x)
{
    buff->first--;
    if(buff->first < 0)
            buff->first = buff->length - 1;
    int index = buff->first;
    buff->buffer[index] = x;
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, leftBorder = 0, rightBorder = 0, windowMax;
    scanf("%d", &n);
    char *commandString = (char*) malloc((2*n - 1)*sizeof(char));
    int *arr = (int*) malloc(n*sizeof(n));
    for(int i = 0; i < n; i++)
        scanf("%d ", &arr[i]);
    scanf("\n");
    scanf("%s", commandString);
    deque *d = createDeque(n);
    for(int i = 0; i < (2*n-1); i++)
    {
        if (commandString[i] == 'R')
        {
            rightBorder++;
            pushToFront(d, arr[rightBorder-1]);
        }
        else
        {
            leftBorder++;
            if (getFromBack(d) == arr[leftBorder-1])
                popFromBack(d);
        }
        windowMax = getFromBack(d);
        printf("%d\n", windowMax);
    }
    return 0
