#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define N 25e4

uint64_t A, B, M, R, S;
uint32_t hashFunc(uint32_t x)
{
    return (((A*x + B) % M) % R) / S;
}

double avalancheEff[32][32];

void setToZero(double *arr[32])
{
    memset(arr, 0, 32*32*sizeof(double));
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    setToZero(avalancheEff);
    uint32_t hash, test, testCheck, hashCheck, difference;
    scanf("%llu %llu %llu %llu %llu", &A, &B, &M, &R, &S);
    for(int i = 0; i < N; i++)
    {
        test = rand() + (rand()<<8) + (rand()<<16) + (rand()<<24);
        hash = hashFunc(test);
        for(int j = 0; j < 32; j++)
        {
            if ((test  & (1<<j)))
                testCheck = test - (1<<j);
            else
                testCheck = test + (1<<j);
            hashCheck = hashFunc(testCheck);
            difference = hash ^ hashCheck;
            for(int k = 0; k < 32; k++)
                if (difference & (1<<k))
                {
                    avalancheEff[j][k]++;
                }
        }
    }
    for(int i = 0; i < 32; i++)
    {
        for(int j = 0; j < 32; j++)
        {
            avalancheEff[i][j] =  100.0*avalancheEff[i][j]/(1.0*N);
            printf("%3.0lf ", avalancheEff[i][j]);
        }
        printf("\n");
    }
    return 0;
}
