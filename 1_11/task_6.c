#include <stdio.h>
#include <stdlib.h>
#define N 100000

int compare(const void * x1, const void * x2)
{
	return (*(int*)x1 - *(int*)x2);
}


int BinSearch(int arr[], int n, int x)
{
    int m;
    int l = 0;
    int r = n-1;
    m = (r + l)/2;
    while (arr[m] != x)
    {
        m = (r + l)/2;
        if (l > r)
            return -1;
        if (arr[m] < x)
        {
            l = m+1;
        }
        else
        {
            r = m-1;
        }
    }
    return l;
}

int a[N];
int b[N];
int c[N];


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k, d = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &b[i]);
	}

	qsort(a, n, sizeof(int), compare);
	qsort(b, k, sizeof(int), compare);

    int i = 0;
	while (i < n)
    {
        while ((i < n) && (a[i+1] == a[i]))
            i++;
        if (BinSearch(b, k, a[i]) == -1)
        {
            c[d] = a[i];
            d++;
        }
        i++;
	}

	printf("%d\n", d);
	for (int i = 0; i < d; i++)
		printf("%d ", c[i]);
	return 0;
}

