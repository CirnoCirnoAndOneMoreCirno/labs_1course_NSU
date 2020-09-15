#include <stdio.h>
#define N 100000

void ShakerSort(int a[], int n)
{
    int left = 0;
    int right = n - 1;
    int i, c;
    int f = 1;
    while(f)
    {
        f = 0;
        i = left;
        while (i < right)
        {
            if (a[i] > a[i+1])
            {
                c = a[i];
                a[i] = a[i + 1];
                a[i + 1] = c;
                f = 1;
            }
            i++;
        }
        right--;
        if (f)
        {
            f = 0;
            i = right;
            while (i > left)
            {
                if(a[i] < a[i - 1])
                {
                    c = a[i];
                    a[i] = a[i - 1];
                    a[i - 1] = c;
                    f = 1;
                }
                i--;
            }
        }
        left++;
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

    ShakerSort(a, n);

	for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
	return 0;
}
