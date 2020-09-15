#include <stdio.h>
#define N 325501

typedef unsigned int bitword;

void bitsetZero(bitword *a, int num)
{
    memset(a,0,sizeof(int)*N);
}

int bitsetGet(bitword *a, int idx)
{
    int byteNum = idx/32;
    int bitNum = idx%32;
    return (a[byteNum] & 1<<(32 - bitNum)) != 0;
}

void bitsetSet(bitword *a, int idx, int newval)
{
    int byteNum = idx/32;
    int bitNum = idx%32;
    if (newval)
        a[byteNum] =  a[byteNum] | 1<<(32 - bitNum);
    else
        a[byteNum] =  a[byteNum] & ~(1<<(32 - bitNum));
}

int bitsetAny (bitword *a, int left, int right)
{
    int posRight = right/32;
    posRight*=32;
    int posLeft = left/32;
    posLeft = posLeft*32 + 32;


    for (int idx = left; ((idx < posLeft) && (idx < right)); idx++)
        if (bitsetGet(a, idx))
            return 1;

    for(int idx = posRight; ((idx < right) && (idx > left)); idx++)
        if (bitsetGet(a, idx))
            return 1;
    posLeft/=32;
    posRight/=32;
    for(int idx = posLeft; idx < posRight; idx++)
        if (a[idx] != 0)
            return 1;
    return 0;
}

bitword a[N];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int q, command, arg1, arg2;
    scanf("%d", &q);
    for(int i = 0; i < q; i++)
    {
        scanf("%d%d", &command, &arg1);
        if ((command == 2) || (command == 3))
            scanf("%d", &arg2);
        if (command == 0)
            bitsetZero(a, arg1);
        else if (command == 1)
        {
            printf ("%d \n", bitsetGet(a, arg1));
        }
        else if (command == 2)
            bitsetSet(a, arg1, arg2);
        else
        {
            if (bitsetAny(a, arg1, arg2))
                printf("some \n");
            else
                printf("none \n");
        }
    }
    return 0;
}

