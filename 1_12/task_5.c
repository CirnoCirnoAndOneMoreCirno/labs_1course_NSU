#include <stdio.h>
#define  N 1000001

typedef struct StringList_s
{
	int countOfStrings;
	char **string;
}StringList;

StringList strings[N];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k, index;
	scanf("%d", &n);

	for (int i = 0; i < N; i++)
	{
		strings[i].string = malloc(sizeof(char *));
		strings[i].countOfStrings = 0;
	}

	for (int i = 0; i < n; i++)
	{
		char *str = malloc(8 * sizeof(char));
		scanf("%d %s\n", &k, str);
		index = strings[k].countOfStrings;
		if (index != 0)
		{
			strings[k].string = realloc(strings[k].string, (strings[k].countOfStrings + 1) * sizeof(char *));

		}
		strings[k].string[index] = str;
		strings[k].countOfStrings++;
	}
	for (int i = 0; i < N; i++)
	{
		if (strings[i].countOfStrings > 0)
		{
			for (int j = 0; j < strings[i].countOfStrings; j++)
			{
				printf("%d %s \n", i, strings[i].string[j]);
			}
		}
	}
	return 0;
}
