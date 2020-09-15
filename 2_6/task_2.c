#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct asmp_s
{
    double exp, lg, power, cnst;
}asmp;

void asmpRead(asmp *a)
{
    a->exp = 1;
    a->cnst = 1;
    a->lg = 0;
    a->power = 0;
    char *str = malloc(sizeof(char) * 100);
    char *token = strtok(str, " ");
    gets(str);
    while(token)
    {
        if (token[0] == 'N')
        {
            if(token[1] == '^')
            {
                token = token + 2;
                a->power = strtod(token, NULL);
            }
            else
            {
                a->power = 1;
            }
        }
        else if (token[0] == 'l')
        {
            token+=4;
            if (token[0] == '^')
            {
                token++;
                a->lg = strtod(token, NULL);
            }
            else
                a->lg = 1;
        }
        else if ((token[0] >= '0') && (token[0] <= '9'))
        {
            int i = 0;
            while ((token[i] != '^') && (token[i] != '\0'))
                i++;
            if (token[i]=='^')
            {
                a->exp = strtod(token, NULL);
            }
            else
                a->cnst = strtod(token, NULL);
        }
        token = strtok(NULL, " ");
    }
    free(str);
    free(token);
}

int asmpComp (asmp a1, asmp a2)
{
    if (a1.exp > a2.exp)
        return 1;
    if (a1.exp < a2.exp)
        return -1;

    if (a1.power > a2.power)
        return 1;
    if (a1.power < a2.power)
        return -1;

    if (a1.lg > a2.lg)
        return 1;
    if (a1.lg < a2.lg)
        return -1;

    if (a1.cnst > a2.cnst)
        return 1;
    if (a1.cnst < a2.cnst)
        return -1;
    return 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    char trash[10];
    asmp a1, a2;
    scanf("%d", &n);
    gets(trash);
    for(int i = 0; i < n; i++)
    {
        asmpRead(&a1);
        asmpRead(&a2);
        printf("%d\n", asmpComp(a1, a2));
    }
    return 0;
}
