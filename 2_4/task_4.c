#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MOD 100003

typedef struct list_s
{
    int val;
    unsigned int key;
    struct list_s *next;
}list;

list *hashTable[MOD] = {NULL};

void addToHash(int num, unsigned int k, list **hashTable)
{
    int hash = abs(k%MOD);
    list *tmp = (list*) malloc(sizeof(list));
    tmp->next = hashTable[hash];
    tmp->val = num;
    tmp->key = k;
    hashTable[hash] = tmp;
}

int checkNumForCollision(unsigned int k, list **hashTable)
{
    int col = -1;
    int hash = abs(k % MOD);
    list *tmp = hashTable[hash];
    //printf("%d \n", hash);
    while(tmp != NULL)
    {
        if(tmp->key == k)
            col = tmp->val;
        tmp = tmp->next;
    }
    return col;
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
            printf("%u ", tmp->key);
            tmp = tmp->next;
        }
    }
}
int main()
{
    int num = 1, collision1 = -1, collision2 = 0;
    unsigned int hash;
    printf("eval 1\n");
    fflush(stdout);
    scanf("%u", &hash);
    addToHash(1, hash, hashTable);
    while ((collision1 == -1) && (num <= 200000))
    {
        num++;
        printf("eval %u\n", num);
        fflush(stdout);
        scanf("%u", &hash);
        collision1 = checkNumForCollision(hash, hashTable);
        addToHash(num, hash, hashTable);
    }
    collision2 = num;
    printf("answer %d %d", collision1, collision2);
    return 0;
}
