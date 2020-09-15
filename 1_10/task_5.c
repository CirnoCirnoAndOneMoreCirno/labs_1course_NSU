#include <stdio.h>
#include <string.h>
#define N 101

int CalcLetters(char *iStr, int *oLowerCnt, int *oUpperCnt, int *oDigitsCnt)
{
    *oLowerCnt = 0;
    *oUpperCnt = 0;
    *oDigitsCnt = 0;
    int len = 0;
    int i = 0;
    char c;
    while (iStr[i] != '\0')
    {
        c = iStr[i];
        if ((c >= 48) && (c <= 57))
            (*oDigitsCnt)++;
        else if ((c >= 65) && (c <= 90))
            (*oUpperCnt)++;
        else if ((c >= 97) && (c <= 122))
            (*oLowerCnt)++;
        len++;
        i++;
    }
    return len;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char str[N];
    int lowerCnt = 0, uppperCnt = 0, digitsCnt = 0, len;
    int *np = 1;
    int i = 1;
    while (np)
    {
        np = gets(str);
        if (np)
        {
            len = CalcLetters(str, &lowerCnt, &uppperCnt, &digitsCnt);
            printf("Line %d has %d chars: %d are letters (%d lower, %d upper), %d are digits.\n",
                    i, len, lowerCnt+uppperCnt, lowerCnt, uppperCnt, digitsCnt);
        }
        i++;
    }
    return 0;
}

