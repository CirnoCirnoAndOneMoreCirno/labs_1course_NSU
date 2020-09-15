#include <stdio.h>
#include <string.h>
#define N 101
#define M 1000001

int glLen;

char* Concat(char *pref, char *suff)
{
	int l2 = strlen(suff);
	int i;
	for (i = glLen; (i - glLen) < l2; i++)
		pref[i] = suff[i - glLen];
	pref[i] = '\0';
	glLen += l2;
	return pref;

}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, len;
	char s[N];
	char res[M];
	scanf("%d", &n);
	scanf("%s", res);
	glLen = strlen(res);
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%s", s);
		Concat(res, s);
	}
	printf("%s", res);
	return 0;
}
