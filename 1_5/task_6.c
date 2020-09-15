#include <stdio.h>
#include <stdlib.h>
#define N 26
#define M 20


int main()
{
	char alph[N];
	char str[M];
	int d = 0;
    int i = 0;
    int isLetInWord = 1;
    int isEndOfString = 0;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	for (i = 'a';  i <= 'z'; i++)
    {
        alph[i - 'a'] = i;
    }

    d = 0;
    i = 0;

    while (!(isEndOfString) && (isLetInWord))
    {
        isEndOfString = scanf("%s", str);
        isEndOfString = (isEndOfString == EOF);
        isLetInWord = 0;
        i = 0;
        if (!(isEndOfString))
        {
            while (str[i] != '\0')
            {
                if (str[i]==alph[d])
                {
                    isLetInWord = 1;
                }
                i++;
            }
        }
        else
            isLetInWord = 1;
        d++;
    }
    d--;
    if (isLetInWord)
        printf("NO WINNER");
    else if (d%2 == 0) //ѕровер€ем, на какой букве остановилась игра
        printf("PLAYER 2");
    else
        printf("PLAYER 1");
	return 0;
}
