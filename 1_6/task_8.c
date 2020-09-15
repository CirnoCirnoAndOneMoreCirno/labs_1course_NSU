#include <stdio.h>
#include <string.h>
#define N 3000
#define BASE 1000000000

int StringToLongNum(int num[], char str[])
{
    int i = strlen(str) - 1;
    int j = 0;
    int s = 1;
    while (i >= 0)
    {
        num[j] += s*(str[i] - '0');
        s*=10;
        if (s == BASE)
        {
            s = 1;
            j++;
        }
        i--;
    }
    return j+1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int num1[N] = {0};
    int num2[N] = {0};
    int result[N] = {0};
    char str[N];
    int len1, len2, lenRes, carry = 0;
    long long cur;
    scanf("%s", str);
    len1 = StringToLongNum(num1, str);
    scanf("%s", str);
    len2 = StringToLongNum(num2, str);
    lenRes = len1 + len2 + 1;
    for(int i = 0; i < len1; i++)
    {
        for(int j = 0; (j < len2) || (carry) ; j++)
        {
            cur = result[i + j] + 1LL*num1[i]*(j < len2 ? num2[j]:0) + carry;
            result[i + j] = cur%BASE;
            carry = cur/BASE;
        }
    }
    for(int i = lenRes; result[i] == 0; i--)
        lenRes--;
    printf("%d", result[lenRes]);
    for(int i = lenRes-1; i >= 0; i--)
        printf("%09d", result[i]);
    return 0;
}
