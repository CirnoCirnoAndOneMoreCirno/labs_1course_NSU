#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MOD 2000003

typedef struct list_s
{
    int val;
    unsigned long long int key;
    struct list_s *next;
}list;

list *hashTable[MOD] = {NULL};
int a, b, c;
unsigned long long int M;

void addToHash(int num, unsigned long long int k, list **hashTable)
{
    int hash = abs(k%MOD);
    list *tmp = (list*) malloc(sizeof(list));
    tmp->next = hashTable[hash];
    tmp->val = num;
    tmp->key = k;
    hashTable[hash] = tmp;
}

int checkNumForCollision(unsigned long long int k, list **hashTable)
{
    int left = -1;
    int hash = abs(k % MOD);
    list *tmp = hashTable[hash];
    //printf("%d \n", hash);
    while(tmp != NULL)
    {
        if(tmp->key == k)
            left = tmp->val;
        tmp = tmp->next;
    }
    return left;
}
void printHashTable (list **hashTable)
{
    list *tmp;
    for(int i = 0; i < MOD; i++)
    {
        tmp = hashTable[i];
        if (tmp != NULL)
            printf("\n%d: ", i);
        while(tmp != NULL)
        {
            printf("%llu ", tmp->key);
            tmp = tmp->next;
        }
    }
}
unsigned long long int func(unsigned long long int s)
{
    return (s*s*a + s*b + c)%M;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%llu", &M);
    scanf("%d%d%d", &a, &b, &c);
    int leftBorder, rightBorder;
    unsigned long long int funcValue = 1;
    addToHash(0, 1, hashTable);
    for(rightBorder = 1; rightBorder <= 2000000; rightBorder++)
    {
        funcValue = func(funcValue);
        leftBorder = checkNumForCollision(funcValue, hashTable);
        addToHash(rightBorder, funcValue, hashTable);
        if (leftBorder != -1)
            break;
    }
    //printHashTable(hashTable);
    printf("%d %d", leftBorder, rightBorder);
    return 0;
}
