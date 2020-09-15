#include <stdio.h>
#define N 1001

typedef struct ringBuffer_s
{
    int buffer[N];
    int indexIn;
    int indexOut;
    int length;
}ringBuffer;

int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

void pushToBuffer(ringBuffer *buff, int x)
{
    int index = buff->indexIn;
    buff->indexIn++;
    if(buff->indexIn >= buff->length)
        buff->indexIn = 0;
    buff->buffer[index] = x;
}

int getFromBuffer(ringBuffer *buff)
{
    int index = buff->indexOut;
    return buff->buffer[index];
}

int popFromBuffer(ringBuffer *buff)
{
    int x = getFromBuffer(buff);
    buff->indexOut++;
    if (buff->indexOut >= buff->length)
        buff->indexOut = 0;
    return x;
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ringBuffer a;
    a.indexIn = 0;
    a.indexOut = 0;
    int n, m, number, sum, trash, flag = 0, x, count = 0;

    scanf("%d %d", &n, &m);
    a.length = n;

    for(int ii = 0; ii < m; ii++)
    {
        scanf("%d", &number);
        if (number >= 0)
        {
            for(int i = 0; i < number; i++)
            {
                if(count >= a.length)
                {
                    if(!flag)
                    {
                        printf("Memory overflow\n");
                        flag = 1;
                    }
                    scanf("%d", &trash);
                }
                else
                {
                    scanf("%d", &x);
                    pushToBuffer(&a, x);
                    count++;
                }
            }
            ii+=number;
        }
        else
        {
            if(count == 0)
                printf("Empty queue\n");
            else
            {
                number*=-1;
                sum = 0;
                for(int i = 0; (i < number) && (i < count); i++)
                {
                    sum+=popFromBuffer(&a);
                }
                printf("%d\n", sum/min(count, number));
                if (number > count)
                {
                    printf("Empty queue\n");
                }
                count = max(0, count - number);
                number = 0;
            }
        }
        flag = 0;
    }
    return 0;
}
