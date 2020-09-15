#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 101
#define EPS 0.00001

int CharToDigit(char c)
{
    if (c <= '9')
        return c - '0';
    else if ((c >= 'a') && (c <= 'z'))
        return c - 'a' + 10;
    return -1;
}

char DigitToChar(int dig)
{
    if (dig <= 9)
        return '0' + dig;
    return 'a' + dig - 10;
}

double FToDecimal(char *num, int base)
{
    double s = 1.0/base;
    double result;
    int i = 0;
    int dig;
    while (num[i]!='\0')
    {
        dig = CharToDigit(num[i]);
        result += dig*s;
        s = s/base;
        i++;
    }
    return result;
}

void FDecimalToAnother(char *newNum, double num, int base, int k)
{
    int a, i;
    char maxDigit = DigitToChar(base-1);
    i = 0;
    while ((i < k) && (num > 0) && (num > EPS))
    {
        num*=base;
        a = num;
        num -=a;
        newNum[i] = DigitToChar(a);
        i++;
        if (num + EPS >= 1)
        {
            break;
        }
    }
    if (num + EPS >= 1)
    {
        newNum[i-1]+=1;
        int t = i-2;
        while ((newNum[t] > maxDigit) && (t > 0))
        {
            newNum[t] = maxDigit;
            newNum[t-1] +=1;
            t--;
        }
    }
    newNum[i] = '\0';
    i--;
    while (newNum[i] == '0')
    {
        newNum[i] = '\0';
        i--;
    }
}

int IntegerToDecimalBase (char num[], int base)
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

int DecimalToAnother(int dec, int base, char *a)
{
    int c;
    int k = 0;
    if (dec == 0)
    {
        k++;
        a[0] = '0';
        a[1] = '\0';
    }
    while (dec > 0)
    {
        a[k] = DigitToChar(dec%base);
        dec = dec/base;
        k++;
    }
    for(int i = 0; i < (k/2); i++)
    {
        c = a[i];
        a[i] = a[k - i - 1];
        a[k - i - 1] = c;
    }
    return k;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int oldBase, newBase, k, decNum, d, j, len;
    double floatNum;
    char oldNum[N], integerPart[N], floatPart[N];
    int isRight = 1;
    scanf("%d%d%d", &oldBase, &newBase, &k);
    scanf("%s", oldNum);
    len = strlen(oldNum);
    int i = 0;
    while ((oldNum[i] != '.') && (i < len))
    {

        integerPart[i] = oldNum[i];
        d = CharToDigit(oldNum[i]);
        i++;
        if ((d >= oldBase) || (d < 0))
        {
            isRight = 0;
            printf("%c ", d);
        }
    }
    integerPart[i] = '\0';
    i++;
    j = 0;
    while (i < len)
    {
        floatPart[j] = oldNum[i];
        d = CharToDigit(oldNum[i]);
        j++;
        i++;
        if ((d >= oldBase) || (d < 0))
            isRight = 0;
    }
    floatPart[j] = '\0';
    if (isRight)
    {
        decNum = IntegerToDecimalBase(integerPart, oldBase);
        memset(integerPart, 0, sizeof(char)*N);
        DecimalToAnother(decNum, newBase, integerPart);
        if (j > 0)
        {
            floatNum = FToDecimal(floatPart, oldBase);
            memset(floatPart, 0, sizeof(char)*N);
            FDecimalToAnother(floatPart, floatNum, newBase, k);
        }
        printf("%s", integerPart);
        if ((j > 0) && (floatNum > 0))
            printf(".%s", floatPart);
    }
    else
        printf("NO");
    return 0;
}
