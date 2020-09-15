#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int x1, x2, x3;
    int y1, y2, y3;
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    scanf("%d%d", &x1, &y1);
    scanf("%d%d", &x2, &y2);
    scanf("%d%d", &x3, &y3);
    double a, b, c;
    a = sqrt(pow(x2-x3, 2) + pow(y2-y3,2));
    b = sqrt(pow(x1-x3, 2) + pow(y1-y3,2));
    c = sqrt(pow(x1-x2, 2) + pow(y1-y2,2));
    double p = (a + b + c)/2.0;
    double s = sqrt(p*(p-a)*(p-b)*(p-c));
    printf("%.3f \n", p*2);
    printf("%.3f ", s);
    return 0;
}
