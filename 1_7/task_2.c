#include <stdio.h>
#define VALUE_BITS 8*sizeof(int)

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int value, count = 0, maxCount = 0;
    scanf("%d", &value);
    for (int i = 0; i < VALUE_BITS; i++)
    {
        if (value & 1)
            count++;
        else
        {
            if (count > maxCount)
                maxCount = count;
            count = 0;
        }
        value >>= 1;
    }
    if (count > maxCount)
        maxCount = count;
    printf("%d", maxCount);
    return 0;
}
