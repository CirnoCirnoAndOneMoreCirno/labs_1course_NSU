#include <stdio.h>
#define VALUE_BITS 8*sizeof(int)

bitPrint(int n, unsigned m)
{
    if (0==m) return;
        bitPrint(n,m<<1);
    printf("%d",0!=(n&m));
}
int bitRev(int value)
{
    int result = 0;
    for(int i = 0; i < VALUE_BITS; i++)
    {
        result = (result << 1) | (value & 1);
        value >>= 1;
    }
    return result;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int value, revValue;
    scanf("%d", &value);
    bitPrint(value, 1);
    printf("\n");
    revValue = bitRev(value);
    printf("%d \n", revValue);
    bitPrint(revValue, 1);
    return 0;
}
