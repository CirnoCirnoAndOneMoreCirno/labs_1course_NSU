#include <stdio.h>
#include <string.h>
#define N 101

void Reverse(char *start, int len)
{
	char swap;
	for (int i = 0; i < (len / 2); i++)
	{
		swap = start[i];
		start[i] = start[len - i - 1];
		start[len - i - 1] = swap;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, len;
	char s[N];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s);
		len = strlen(s);
		Reverse(s, len);
		printf("%s\n", s);
	}
	return 0;
}
