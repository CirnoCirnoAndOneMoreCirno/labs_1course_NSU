#include <stdio.h>
#define N 41

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int num;
    int p[N];
    p[1] = 2;
    p[2] = 3;

    scanf("%d", &num);

    for(int i = 3; i <= num; i++)
    {
        p[i] = p[i-1] + p[i-2];
    }
    printf("%d", p[num]);
    return 0;
}
