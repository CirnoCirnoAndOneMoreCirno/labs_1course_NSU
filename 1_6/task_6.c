#include <stdio.h>
#include <string.h>
#define N 51
int GetDigit(char dig)
{
    if (dig <= '9')
        return dig - '0';
    return dig - 'a' + 10;
}

double FToDecimal(char *num, int base)
{
    double s = 1.0/base;
    double result;
    int i = 0;
    int dig;
    while (num[i]!='.')
        i++;
    i++;
    while (num[i]!='\0')
    {
        dig = GetDigit(num[i]);
        result += dig*s;
        s = s/base;
        i++;
    }
    return result;

}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int base;
    double newNum;
    char num[N];

    scanf("%d", &base);
    scanf("%s", num);

    newNum = FToDecimal(num, base);
    printf("%.5lf", newNum);
    return 0;
}
