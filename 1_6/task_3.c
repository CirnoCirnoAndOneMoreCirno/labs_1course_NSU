#include <stdio.h>
#include <string.h>
#define N 25

int ToDecimalBase (char num[], int base)
{
    int k = strlen(num);
    int result = 0;
    int s = 1;
    int digit;
    for(int i = k-1; i>=0; i--)
    {
        if (num[i] <= '9')
            digit = num[i] - '0';
        else
            digit = num[i] - 'a' + 10;
        result = result + digit*s;
        s*=base;
    }
    return result;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int base, newNum;
    char num[N];
    scanf("%d", &base);
    scanf("%s", num);
    newNum = ToDecimalBase(num, base);
    printf("%d", newNum);
    return 0;
}
