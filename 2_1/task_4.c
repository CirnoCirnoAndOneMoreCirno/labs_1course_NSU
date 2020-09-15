#include <stdio.h>
#define ERROR_DEQUE_IS_EMPTY 1000007
typedef struct ringBuffer_s
{
    int first;
    int actualSize;
    int *buffer;
    int length;
}ringBuffer;

ringBuffer *createBuffer(int length)
{
    ringBuffer *b = malloc(sizeof(ringBuffer));
    b->buffer = malloc(length * sizeof(int));
    b->length = length;
    b->first = -1;
    b->actualSize = 0;
    return b;
}

void pushToFront(ringBuffer *buff, int x)
{
    buff->actualSize++;
    if (buff->first == -1)
        buff->first = 0;
    int index = (buff->first + buff->actualSize - 1) % buff->length;
    buff->buffer[index] = x;
}

void pushToBack(ringBuffer *buff, int x)
{
   buff->first--;
   buff->actualSize++;
   if(buff->first < 0)
        buff->first = buff->length - 1;
   int index = buff->first;
   buff->buffer[index] = x;
}

int getFromFront(ringBuffer *buff)
{
    int index = (buff->first + buff->actualSize - 1) % buff->length;
    return buff->buffer[index];
}

int getFromBack(ringBuffer *buff)
{
    int index = buff->first;
    return buff->buffer[index];
}

int popFromFront(ringBuffer *buff)
{
    if (buff->actualSize == 0)
        return ERROR_DEQUE_IS_EMPTY;
    int x = getFromFront(buff);
    buff->actualSize--;
    return x;
}

int popFromBack(ringBuffer *buff)
{
    if (buff->actualSize == 0)
        return ERROR_DEQUE_IS_EMPTY;
    int x = getFromBack(buff);
    buff->first++;
    buff->actualSize--;
    if (buff->first >= buff->length)
        buff->first = 0;
    return x;
}

ringBuffer* getFilledDeque(int sign, int n)
{
    ringBuffer *deque = createBuffer(2*n + 1);
    //pushToBack(deque, sign);
    for(int i = 0; i < n; i++)
    {
        pushToBack(deque, (i + 1)*sign);
    }
    return deque;
}

void printDeque(ringBuffer *deque)
{
    printf("%d ", deque->actualSize);
    while(deque->actualSize != 0)
        printf("%d ", popFromFront(deque));
    printf("\n");
}

int readCommand()
{
    char command;
    scanf("%c", &command);
    if ((command >= '0') && (command <= '9'))
        return command - '0';
    return command - 'A' + 10;
}

int takeCard (ringBuffer *packRight, ringBuffer *packLeft, int command)
{
    int isRightPack = command & 8;
    int isFromBack = command & 4;
    if (isRightPack)
    {
        if (isFromBack)
            return popFromBack(packRight);
        return popFromFront(packRight);
    }
    else
    {
        if (isFromBack)
            return popFromBack(packLeft);
        return popFromFront(packLeft);
    }
}

void putCard(ringBuffer *packRight, ringBuffer *packLeft, int command, int card)
{
    int isRightPack = command & 2;
    int isToBack = command & 1;
    if (isRightPack)
    {
        if (isToBack)
            pushToBack(packRight, card);
        else
            pushToFront(packRight, card);
    }
    else
    {
        if (isToBack)
            pushToBack(packLeft, card);
        else
            pushToFront(packLeft, card);
    }
    return;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m, command, card, trash;
    scanf("%d%d", &n, &m);
    ringBuffer *packLeft = getFilledDeque(1, n);
    ringBuffer *packRight = getFilledDeque(-1, n);
    scanf("%c", &trash);
    for(int i = 0; i < m; i++)
    {
        command = readCommand();
        if ((command != 0) && (command != 5) && (command != 10) && (command != 15))
        {
            card = takeCard(packRight, packLeft, command);
            //printf("taken card : %d\n", card);
            if (card != ERROR_DEQUE_IS_EMPTY)
                putCard(packRight, packLeft, command, card);
        }
    }
    printDeque(packLeft);
    printDeque(packRight);
    return 0;
}
