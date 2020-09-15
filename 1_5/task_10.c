#include <stdio.h>
#include <stdlib.h>
#define N 1000

int main()
{
    int i, j, flag, isEOF;
    char s1[N];
    char s2[N];
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%s", s1);
    i = 0;
    isEOF = 0;
    while (!isEOF)
    {
        isEOF = scanf("%s", s2);
        isEOF = (isEOF == EOF);
        if (!isEOF)
        {
            i = 0;
            j = 0;
            flag = 0;
            while (s1[i] != '\0')
            {
                j = 0;
                while(s2[j] != '\0')
                {
                    if (s1[i] == s2[j])
                        flag = 1;
                    j++;
                }
                i++;
            }
            if (!flag)
            {
                printf("%s \n", s2);
            }
        }
    }
    return 0;
}
