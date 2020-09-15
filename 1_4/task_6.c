#include <stdio.h>
#define N 1000

void recover_transp(int a[], int n, int p[])
{
    int j, d, l;

    d = 1;
	for (int i = 0; i < n; i++)
    {
        l = 0;
        for(j = 0; j < n; j++)
        {
            if (p[j]==0)
            {
                if (l == a[i])
                {
                    p[j] = d;
                    break;
                }
                else
                {
                    l++;
                }
            }
        }
        d++;
    }
}

int IsRightTransp(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if (a[i]==0)
            return 0;
    }
    return 1;
}

int main()
{
	int n;
    int a[N] = { 0 };
    int p[N] = {0};

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	recover_transp(a, n, p);
    if (IsRightTransp(p, n))
        for(int i =0; i < n; i++)
            printf("%d ", p[i]);
    else
        printf("NO");
	return 0;
}
