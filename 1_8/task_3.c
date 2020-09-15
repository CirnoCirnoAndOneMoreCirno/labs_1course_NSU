#include <stdio.h>
#define N 201


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, cnt;
	double m, c, c1;
	double x[N];
	double a[N][N+1];
	int isDiag = 1;
    int isLinear = 1;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n + 1; j++)
			scanf("%lf", &a[i][j]);
	}

    for(int i = 0; i < n; i++)
    {
        cnt = 0;
        for(int j = 0; j < n; j++)
        {
            if (a[i][j] != 0.0)
                cnt++;
        }
        if (cnt > 1)
        {
            isLinear = 0;
        }
        if (a[i][i] != 0.0)
            isDiag = 0;
    }
    if (isDiag)
    {
        for(int  j = 0; j < n+1; j++)
        {
            c = a[n-1][j];
            for(int i = n-1; i >= 0; i--)
            {
                a[i][j] = a[i-1][j];
            }
            a[0][j] = c;
        }
    }
    if (!isLinear)
    {
        for (int k = 1; k < n; k++)
        {
            for (int j = k; j < n; j++)
            {
                    m = a[j][k - 1] / a[k - 1][k - 1];
                    for (int i = 0; i < n + 1; i++)
                        a[j][i] = a[j][i] - m*a[k - 1][i];
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
                x[i] = a[i][n] / a[i][i]; // !!!!!!!!!!!!!!!!
                for (int c = n - 1; c > i; c--)
                {
                    x[i] = x[i] - a[i][c] * x[c] / a[i][i];
                }
        }
    }
    else
    {
        int i, j;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(a[i][j] != 0.0)
                    break;
            }
            x[j] = a[i][n] / a[i][j];
        }
    }
	for (int i = 0; i < n; i++)
	{
		printf("%lf\n", x[i]);
	}
	return 0;
}

