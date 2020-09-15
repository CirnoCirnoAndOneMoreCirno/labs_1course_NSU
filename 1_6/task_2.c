#include <stdio.h>
#include <stdlib.h>
#define N 25
#define M 16

int DecimalToAnother(int dec, int base, char *a)
{
    char alph[M];
    int c;
    for (int i = '0'; i <= '9'; i++)
    {
        alph[i - '0'] = i;
    }
    for (int i = 'a'; i <= 'f'; i++)
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
    return k;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int base, n, l;
    char numInNewBase[N];
    numInNewBase[1] = '0';
    scanf("%d%d", &base, &n);
    l = DecimalToAnother(n, base, numInNewBase);
    if (n==0)
        l++;
    for(int i = 1; i < l; i++)
        printf("%c", numInNewBase[i]);
    return 0;
}
