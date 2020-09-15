#include <stdio.h>
#include <string.h>
#define M 20
#define N 100

void DeleteExtraChars(char s[], int len)
{
    int i = len - 1;
    while ((s[i] < 65) || (s[i] > 90))
    {
        s[i] = 0;
        i--;
    }
}

void ToUpperRegister(char s[], int len)
{
    for(int i = 0; i < len; i++)
    {
        if ((s[i]>= 97) && (s[i] <= 122))
            s[i]-=32;
    }
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char exceptionalWords[M][N];
	char wordsList[N][N];
	char word[N];
	int countOfWord[N] = {0};
	char c;
	int l = 0, d = 0, isEndOfArticle = 0, len, isWordInList, isException;
	while (c != 10)
    {
        scanf("%s", exceptionalWords[l]);
        scanf("%c", &c);
        ToUpperRegister(exceptionalWords[l], strlen(exceptionalWords[l]));
        l++;
    }

    while (!isEndOfArticle)
    {
        scanf("%s", word);
        len = strlen(word);
        isEndOfArticle = (word[len-1]=='*');
        ToUpperRegister(word, len);
        DeleteExtraChars(word, len);
        isWordInList = 0;
        isException = 0;
        for(int i = 0; i < l; i++)
        {
            if (strcmp(word, exceptionalWords[i]) == 0)
                isException = 1;
        }
        if (!isException)
        {
            for(int i = 0; ((i < d) && !isWordInList); i++)
            {
                if (strcmp(word, wordsList[i]) == 0)
                {
                    countOfWord[i]++;
                    isWordInList = 1;
                }
            }
            if (!isWordInList)
            {
                strcpy(wordsList[d], word);
                d++;
            }
        }
    }
    int m = 0;
    for(int i = 0; i < d; i++)
    {
        if (countOfWord[i] > countOfWord[m])
            m = i;
    }
    printf("%s", wordsList[m]);
	return 0;
}

