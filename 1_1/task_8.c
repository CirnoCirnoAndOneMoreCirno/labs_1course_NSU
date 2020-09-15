#include <stdio.h>

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m, p, k, l;
	scanf("%d", &n);
	scanf("%d%d%d%d", &m, &p, &k, &l);
	m--;
	int d = m / ((p - 1)*l + k - 1); //кол-во квартир на этаже
	int p1, k1, x;
	x = n / d; //кол-во этажей без учета подъездов
	if ((n%d) != 0)
		x++;
	p1 = 1 + x / l; //!!
	if ((x%l)==0)
		p1--;
	k1 = x%l;
	if (k1 == 0)
		k1 = l;
	printf("%d %d", p1, k1);
	return 0;
}
