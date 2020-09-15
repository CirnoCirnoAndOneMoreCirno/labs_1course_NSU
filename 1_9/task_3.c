#include <stdio.h>

int main()
{
	FILE *input;
	FILE *output;
	input = fopen("input.txt", "r");
	output = fopen("output.txt", "w");
	int ans = 0;
	char c;
	while (fscanf(input, "%c", &c) != -1)
	{
		if (c == '\n')
			ans++;
	}
	//ans++;
	fprintf(output, "%d", ans);
	fclose(input);
	fclose(output);
	return 0;
}
