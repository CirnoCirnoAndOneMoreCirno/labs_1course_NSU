#include <stdio.h>

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int dec = 1; //кол-во цифр в числе
	int maxNum = 9;
	int i = 1;
	int num = 1;
	int k;
	int ans = 0;
	scanf("%d", &k);
	while ((i + dec - 1) < k)
	{
		i += dec;
		num++;
		if (num>maxNum)
		{
			dec++;
			maxNum = maxNum * 10 + 9;
		}

	}
	for (int j = 0; j < (dec + i - k); j++)
	{
		ans = num % 10;
		num /= 10;
	}
	printf("%d", ans);
	return 0;
}
