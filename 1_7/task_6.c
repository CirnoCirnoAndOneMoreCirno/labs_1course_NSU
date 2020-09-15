#include <stdio.h>
#define N 100

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a[N] = {0};
    int n, k, bitVal, bitNum, idNum;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < k; i++)
    {
        scanf("%d%d", &bitVal, &bitNum);
        idNum = bitNum / 32;
        bitNum = bitNum%32;
        if (bitVal)
            a[idNum] = a[idNum] | 1<<(31 - bitNum);
        else
            a[idNum] = a[idNum] & ~(1<<(31 - bitNum));
    }
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}

