#include <stdio.h>
#include <math.h>
#define N 100

void countNewDivisors(int mods[][2], int num, int k)
{
    for(int j = 0; j < k; j++)
    {
        if (mods[j][0] - mods[j][1])
        {
            int index = abs((j + num%k)%k);
            mods[index][0]++;
            mods[index][1] += 1;
        }
    }
}

void clearPrevStep(int mods[][2], int k)
{
    for(int j = 0; j < k; j++)
    {
        if (!mods[j][1])
        {
            mods[j][0] = 0;
        }
        mods[j][1] = 0;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int num, n, k, d;
    int mods[N][2]; // mods[i][0] - кол-во остатков равных i, mods[i][1] - не использовался ли остаток на этом же шаге
    for(int i = 0; i < N; i++)
    {
        mods[i][0] = 0;
        mods[i][1] = 0;
    }
    scanf("%d%d", &n, &k);
    scanf("%d", &num);
    d = 1;
    while (((num % k) == 0) && (d < n))
    {
        scanf("%d", &num);
        d++;
    }

    mods[abs(num%k)][0] = 1;

    for(int i = 0; i < n-d; i++)
    {
        scanf("%d", &num);
        /**if (i != n-d)
            clearPrevStep(mods, k);**/ //необходимо удалять все остатки кроме тех, что получены на последнем шаге
        countNewDivisors(mods, num, k);
        countNewDivisors(mods, -num, k);
        if (i != n-d)
            clearPrevStep(mods, k);
    }


    if (mods[0][0])
        printf("Divisible");
    else
        printf("Not divisible");
    return 0;
}

