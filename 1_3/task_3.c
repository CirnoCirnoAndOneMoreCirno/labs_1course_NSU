#include <stdio.h>
#define M 10001


int main()
{
    int count[M] = {0};
    int n, a, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a);
        count[a]++;
    }
    for(i = 0; i < M; i++)
    {
        if(count[i]>0)
            printf("%d: %d \n", i, count[i]);
    }
    return 0;
}
