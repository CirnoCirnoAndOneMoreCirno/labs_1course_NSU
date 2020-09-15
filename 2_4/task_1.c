#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MOD 1000003

typedef struct list_s
{
    int val;
    struct list_s *next;
}list;

list *hashTable[MOD] = {NULL};

void addToHash(int num, list **hashTable)
{
    int hash = abs(num%MOD);
    list *tmp = (list*) malloc(sizeof(list));
    tmp->next = hashTable[hash];
    tmp->val = num;
    hashTable[hash] = tmp;
}

int numIsUnique(int num, list **hashTable)
{
    int ans = 1;
    int hash = abs(num%MOD);
    list *tmp = hashTable[hash];
    while(tmp != NULL)
    {
        if(tmp->val == num)
            ans = 0;
        tmp = tmp->next;
    }
    return ans;
}

int deleteDuplicates(int *arr, int len, int *newArr)
{
    int countOfUnique = 0;
    for(int i = 0; i < len; i++)
    {
        if (numIsUnique(arr[i], hashTable))
        {
            addToHash(arr[i], hashTable);
            newArr[countOfUnique] = arr[i];
            countOfUnique++;
        }
    }
    return countOfUnique;
}

int main()
{
    FILE *in = fopen("input.bin", "rb");
    FILE *out = fopen("output.bin", "wb");
    int len, lenWithoutDuplicates = 0;
    int *arr, *arrWithoutDuplicates;

    fread(&len, sizeof(int), 1, in);
    arr = (int*) malloc(len*sizeof(int));
    arrWithoutDuplicates = (int*) malloc(len*sizeof(int));
    fread(arr, sizeof(int), len, in);

    lenWithoutDuplicates = deleteDuplicates(arr, len, arrWithoutDuplicates);

    fwrite(&lenWithoutDuplicates, sizeof(int), 1, out);
    fwrite(arrWithoutDuplicates, sizeof(int), lenWithoutDuplicates, out);

    return 0;
}

