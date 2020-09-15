#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 100

typedef struct gangster_s
{
	int time;
	int money;
	int width;
}gangster;


void swap(gangster *a, gangster *b)
{
	gangster c = *a;
	*a = *b;
	*b = c;
}

void SelectionSort(gangster *a, int n)
{
	int r;
	for (int i = 0; i < (n - 1); i++)
	{
		r = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j].time < a[r].time)
			{
				r = j;
			}
		}
		swap(&a[i], &a[r]);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k, t, maxMoney, p;
    int ans[N] = {0};
	scanf("%d%d%d", &n, &k, &t);
	gangster *gang = (gangster*)malloc(n * sizeof(gangster));

	for (int i = 0; i < n; i++)
		scanf("%d", &gang[i].time);
	for (int i = 0; i < n; i++)
		scanf("%d", &gang[i].money);
	for (int i = 0; i < n; i++)
		scanf("%d", &gang[i].width);

	SelectionSort(gang, n);

	for (int i = 0; i < n; i++)
	{
		if ((gang[i].width > gang[i].time) || (gang[i].time > t) || (gang[i].width > k))
			continue;
		else
		{
			maxMoney = gang[i].money;
			p = maxMoney;
			for (int prev = 0; prev < i; prev++)
			{
				if (abs(gang[i].width - gang[prev].width) <= abs(gang[i].time - gang[prev].time))
					p = gang[i].money + ans[prev];
				if (p > maxMoney)
					maxMoney = p;

			}
			ans[i] = maxMoney;
		}
	}
	maxMoney = 0;
	for (int i = 0; i < n; i++)
		if (ans[i] > maxMoney)
			maxMoney = ans[i];
	printf("%d", maxMoney);
	return 0;
}
