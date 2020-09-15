#include <stdio.h>
#define N 1000

int main()
{
	int n, i, j, k;
	int p[N] = {0};
	int a[N] = {0};

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (i = 0; i < n; i++)
        scanf("%d", &p[i]);
    for (i = 0; i < n; i++)
    {
        j = 0;
        k = 0;
        while (p[j]!=(i + 1))
        {
            if (p[j] > (i + 1))
                k++;
            j++;
        }
        a[i] = k;
    }

	for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
