#include <stdio.h>
#define N 257


int main()
{
	FILE *input;
	FILE *output;
	input = fopen("input.txt", "r");
	output = fopen("output.txt", "w");
	int a[N] = { 0 };
	unsigned char c = 0;
	while (c != EOF)
	{
		c = fgetc(input);
		if (c != EOF)
			a[c]++;
	}

	for (int i = 13; i < N; i++)
	{
		c = i;
		if (a[i] > 0)
			fprintf(output, "%d : %c - %d \n", i, c, a[i]);
	}
	fclose(input);
	fclose(output);
	return 0;
}
