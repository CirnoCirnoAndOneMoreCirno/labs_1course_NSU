#include <stdio.h>


int isBis(int year)
{
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))

		return 1;

	return 0;
}

int main()
{
	int sum, d1, d2, m1, m2, y1, y2, c, s1, s2;
	sum = 0;
	int a[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d%d%d%d%d", &d1, &m1, &y1, &d2, &m2, &y2);

	if (((m1 == 2) && (d1 == 29) && !(isBis(y1))) || ((m2 == 2) && (d2 == 29) && !(isBis(y2))) || (y1 <= 0) || (y2 <= 0) || (m1 <= 0) || (m2 <=0)
		|| (d1 <= 0) || (d2 <= 0) || (d1 > a[m1]) || (d2 >  a[m2]))
		printf("ERROR");
	else
	{
		a[2]--;
		s1 = y1 * 365 + y1 / 4 - y1 / 100 + y1 / 400;
		if (isBis(y1) && (m1 <= 2))
			s1--;
		s2 = y2 * 365 + y2 / 4 - y2 / 100 + y2 / 400;
		if (isBis(y2) && (m2 <= 2))
			s2--;
		for (int i = 1; i < m1; i++)
			s1 += a[i];
		for (int i = 1; i < m2; i++)
			s2 += a[i];
		s1 += d1;
		s2 += d2;
		sum = abs(s1 - s2);
		printf("%d", sum);
	}
	return 0;
}
