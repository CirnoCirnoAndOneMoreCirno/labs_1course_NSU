#include <stdio.h>
#define N 1001
int main()
{
	FILE *input;
	FILE *output;
	input = fopen("input.txt", "r");
	output = fopen("output.txt", "w");
	char strings[N][N];
	char c;
	int i = 0, j = 0;
	while (fscanf(input, "%c", &c) != -1)
	{
		if (c != '\n')
		{
			strings[i][j] = c;
			j++;
		}
		else
		{
			strings[i][j] = '\0';
			i++;
			j = 0;
		}
	}
	strings[i][j] = '\0';
	while (i >= 0)
	{
		fprintf(output, "%s\n", strings[i]);
		i--;
	}
	return 0;
}
