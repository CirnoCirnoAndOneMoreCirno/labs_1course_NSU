#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define INF INT_MAX
#define BIT_MASK_LEN 63

//typedef unsigned int bitword;

int maxx(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

void bitsetZero(unsigned long long int *a, int num)
{
    memset(a, 0, sizeof(unsigned long long int)*num);
}

int bitsetGet(unsigned long long int *a, int idx)
{
    int byteNum = idx/64;
    int bitNum = idx%64;
    return (a[byteNum] & 1LL<<(64 - bitNum - 1)) != 0;
}

void bitsetSet(unsigned long long int *a, int idx, int newval)
{
    int byteNum = idx/64;
    int bitNum = idx%64;
    if (newval)
        a[byteNum] =  a[byteNum] | 1LL<<(64 - bitNum - 1);
    else
        a[byteNum] =  a[byteNum] & ~(1<<(64 - bitNum));
}

void doTransitiveClosure(unsigned long long int **matrix, int n)
{
    int k, i, j;
    for( k = 0; k < n; k++)
    {
        for( i = 0; i < n; i++)
        {
            if ((i != k)&&(bitsetGet(matrix[i], k)))
            {
                for( j = 0; j < (n/64 + 1); j++)
                    if (matrix[k][j])
                        matrix[i][j] = (1LL*matrix[i][j]) | (1LL*matrix[k][j]);
            }
        }
        bitsetSet(matrix[k], k, 1);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    char str[2001];
    long long int **matrix = (long long int**) malloc(sizeof(unsigned long long int*) * n);
    for(int i = 0; i < n; i++)
    {
        matrix[i] = (long long int*) malloc(sizeof(unsigned long long int) * (n/64 + 1));
        bitsetZero(matrix[i], (n/64 + 1));
        scanf("%s", str);

        for(int j = 0; j < n; j++)
        {
            if (str[j] == '1')
                bitsetSet(matrix[i], j, 1);
        }
    }
    doTransitiveClosure(matrix, n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d", bitsetGet(matrix[i], j));
        }
        printf("\n");
    }
    return 0;
}

