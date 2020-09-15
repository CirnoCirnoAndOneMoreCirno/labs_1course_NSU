#include <stdio.h>
#include <stdlib.h>
#define N 27

char DigitToChar(int dig)
{
    if (dig <= 9)
        return '0' + dig;
    return 'a' + dig - 10;
}
void FDecimalToAnother(char *newNum, double num, int base, int k)
{
    int a, i;
    i = 0;
    while ((i < k) && (num > 0) && (num > 0.00001))
    {
        num*=base;
        a = num;
        num -=a;
        newNum[i] = DigitToChar(a);
        i++;
    }
    newNum[i] = '\0';
    i--;
    while (newNum[i] == '0')
    {
        newNum[i] = '\0';
        i--;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int b, k;
    double num;
    char newNum[N];
    scanf("%d%d%lf", &b, &k, &num);
    FDecimalToAnother(newNum, num, b, k);
    printf("0.");
    for (int i = 0; newNum[i] != '\0'; i++)
        printf("%c", newNum[i]);
    return 0;
}

