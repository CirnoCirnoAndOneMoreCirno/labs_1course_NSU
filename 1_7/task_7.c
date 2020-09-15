#include <stdio.h>
#include <string.h>
#define N 3002
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
    int n;
    int num[N] = {1};
    int carry = 0;
    long long cur = 0;
    scanf("%d", &n);
    for(int i = 2; i <= n; i++)
    {
        carry = 0;
        for(int j = 0; (j < N) || (carry); j++)
        {
            cur = carry + 1LL*num[j]*i;
            num[j] = cur%BASE;
            carry = cur/BASE;
        }
        /**for(int k = len+1; num[len] == 0; k--)
        {
            len--;
        }**/
    }
    int len = N-1;
    while ((num[len] == 0) && (len >= 1))
        len--;
    printf("%d", num[len]);
    for(int i = len-1; i >= 0; i--)
        printf("%09d", num[i]);
    return 0;
}

