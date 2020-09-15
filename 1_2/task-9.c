#include <stdio.h>

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    double x, eps, y, k;
    int i = 1;
    scanf("%lf%lf", &x, &eps);
    y = x;
    k = x;
    while (((k>eps) && (k>0)) || ((k<-eps) && (k<0)))
    {
        k = -(k*i)/(i+2);
        k*=x*x;
        y+=k;
        i+=2;
    }
    printf("%.5f", y);
    return 0;
}
