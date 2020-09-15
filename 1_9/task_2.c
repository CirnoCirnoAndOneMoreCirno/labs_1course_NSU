#include <stdio.h>
#include <string.h>
#define N 200

int main()
{
	FILE *input;
	FILE *output;
	input = fopen("input.txt", "r");
	output = fopen("output.txt", "w");
	int cnt[N] = { 0 };
	int k = 0;
	char s[N];
	while (fscanf(input, "%s", s) != -1)
	{
		k = strlen(s);
		cnt[k]++;
	}
	for (int i = 1; i < N; i++)
	{
		if (cnt[i] > 0)
			fprintf(output, "%d - %d \n", i, cnt[i]);
	}
	return 0;
}
