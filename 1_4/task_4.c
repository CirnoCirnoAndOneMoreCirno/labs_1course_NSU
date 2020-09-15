#include <stdio.h>
#define N 100000

void SelectionSort(int a[], int n)
{
    int r, c;
    for (int i = 0; i < (n-1); i++)
    {
        r = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[r])
            {
                r = j;
            }
        }
        c = a[i];
        a[i] = a[r];
        a[r] = c;
    }
}

int main()
{
	int n;
    int a[N] = { 0 };

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

    SelectionSort(a, n);

	for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
	return 0;
}
