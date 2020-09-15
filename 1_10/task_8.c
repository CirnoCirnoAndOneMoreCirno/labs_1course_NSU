#include <stdio.h>
#include <stdlib.h>
#define BASE 1000000000

int LongSum(int *a, int *b, int aLen, int bLen)
{
    int carry = 0;
    for (int i=0; ((i < bLen) || carry); i++)
    {
        if (i == aLen)
        {
            a[i] = 0;
            aLen++;
        }
        a[i] += carry + ((i < bLen) ? b[i] : 0);
        carry = a[i] >= BASE;
        if (carry)
            a[i] -= BASE;
    }
    return aLen;
}

typedef struct LongNum_s
{
    int len;
    int arr[500];
} LongNum;

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    LongNum fibs[2];
    fibs[0].len = 1;
    fibs[1].len = 1;
    fibs[0].arr[0] = 1;
    fibs[1].arr[0] = 1;
    int n, lastNum;
    int i = 0, j = 1;
    scanf("%d", &n);
    for (lastNum = 1; lastNum < (n-1); lastNum++)
    {
        fibs[i].len = LongSum(fibs[i].arr, fibs[j].arr, fibs[i].len, fibs[j].len);
        i = (i+1)%2;
        j = (i+1)%2;
    }
    printf("%d", fibs[j].arr[fibs[j].len-1]);
    for(int i = fibs[j].len-2; i >= 0; i--)
        printf("%09d", fibs[j].arr[i]);
    return 0;
}

