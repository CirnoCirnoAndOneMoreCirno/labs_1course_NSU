#include <stdio.h>
#define N 127


int main()
{
	FILE *input;
	FILE *output;
	input = fopen("input.txt", "r");
	output = fopen("output.txt", "w");
	int a[N] = { 0 };
	char c;
	while (!feof(input))
	{
		fscanf(input, "%c", &c);
		a[c]++;
	}

	for (int i = 32; i < N; i++)
	{
		if (a[i] > 0)
		{
			fprintf(output, "%c ", i);
			for (int j = 0; j < a[i]; j++)
				fprintf(output, "#");
			fprintf(output, "\n");
		}
	}
	fclose(input);
	fclose(output);
	return 0;
}
