#include <stdio.h>
#include <stdlib.h>
#define N 27

void InsertionSort(char *a, int n)
{
	int x, j;
    for (int i = 1; i < n; i++)
	{
		x = a[i];
		j = i - 1;
		while ((j > -1) && (a[j] > x))
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}

int main()
{

    char s1[N];
    char s2[N];
    char s3[N];
    int i = 0;
    int j = 0;
    int isInSet;
    int k = 0;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%s", s1);
    scanf("%s", s2);

    while(s1[i] != '\0')
    {
        isInSet = 0;
        j = 0;
        while (s2[j] != '\0')
        {
            if (s1[i]==s2[j])
                isInSet = 1;
            j++;
        }
        if (!(isInSet))
        {
            s3[k] = s1[i];
            k++;
        }
        i++;
    }
    if (!k)
        printf("Empty Set");
    else
    {
        InsertionSort(s3, k);
        for (int i = 0; i < k; i++)
        {
            printf("%c", s3[i]);
        }
    }
    return 0;
}
