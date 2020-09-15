#include <stdio.h>
#define N 1000



int main()
{
	int n, m, i, c;
    int t[N] = { 0 };
    int a[N] = {0};
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

    i = n - 2;
    m = n - 1;
    while ((a[i] > a[i+1])&&(i > 0))
    {
        if (a[i] > a[m])
            m = i;
        i--;
    }
    if (((i == 0) && (a[0] > a[1])) || (n == 1))
    {
        for(i = 0; i < n; i++)
        {
            a[i] = i + 1;
        }
    }
    else
    {
        for(int j = i; j < n; j++)
        {
            if ((a[j] > a[i]) && (a[j] < a[m]))
                m = j;
        }
        c = a[i];
        a[i] = a[m];
        a[m] = c;

        for(int j = i + 1; j <= ((n+i)/2); j++)
        {
            c = a[j];
            a[j] = a[n + i - j];
            a[n + i - j] = c;
        }
    }
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
	return 0;
}
