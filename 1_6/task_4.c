#include <stdio.h>
#include <string.h>
#define N 31
#define M 36

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

int DecimalToAnother(int dec, int base, char *a)
{
    char alph[M];
    int c;
    for (int i = '0'; i <= '9'; i++)
    {
        alph[i - '0'] = i;
    }
    for (int i = 'a'; i <= 'z'; i++)
    {
        alph[i - 'a' + 10] = i;
    }
    int k = 0;
    while (dec > 0)
    {
        a[k] = alph[dec%base];
        dec = dec/base;
        k++;
    }
    k++;
    for(int i = 0; i < (k/2); i++)
    {
        c = a[i];
        a[i] = a[k - i - 1];
        a[k - i - 1] = c;
    }
    if (dec == 0)
        k++;
    return k;
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int oldBase, newBase, decNum, l;
    char num[N], newNum[N];
    newNum[1] = '0';

    scanf("%d%d%s", &oldBase, &newBase, num);
    decNum = ToDecimalBase(num, oldBase);
    l = DecimalToAnother(decNum, newBase, newNum);

    for(int i = 1; i < l; i++)
    {
        printf("%c", newNum[i]);
    }
    return 0;
}
