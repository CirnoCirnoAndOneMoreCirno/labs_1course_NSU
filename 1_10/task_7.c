#include <stdio.h>
#include <string.h>

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int p, q, n, i;
    double x;
    long long m;
    char xr[3], s[10];
    scanf("%d", &n);
    for(int ii = 0; ii < n; ii++)
    {
        p = 0;
        q = 0;
        i = 0;
        scanf("%s%s%llx", s, xr, &m);
        while (s[i] != '/')
        {
            p*=10;
            p+=s[i] - '0';
            i++;
        }
        i++;
        while (s[i] != 0)
        {
            q*=10;
            q+=s[i] - '0';
            i++;
        }
        x = (double)p/q;
        long long* uPtr = (unsigned long long*)&x;
        long long uXor = (*uPtr) ^ m;
        double dXor = *((double*)&uXor);
        printf("%0.15g\n", dXor);
    }
    return 0;
}

