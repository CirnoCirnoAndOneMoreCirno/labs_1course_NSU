#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef union number_u
{
    int decimal;
    char bin[4];
}number;

void swap(char *a, char *b)
{
    char c = *a;
    *a = *b;
    *b = c;
}

int reverseBinNum(int value)
{
    number numToReverse;
    numToReverse.decimal = value;
    swap(&numToReverse.bin[0], &numToReverse.bin[3]);
    swap(&numToReverse.bin[1], &numToReverse.bin[2]);
    return numToReverse.decimal;
}

int main()
{
    FILE *input = fopen("input.bin", "rb");
    FILE *output = fopen("output.bin", "wb");
    int n, num, res = 0, isLittleEndian = 1;
    fread(&n, sizeof(int), 1, input);
    if (n > 10000)
    {
        isLittleEndian = 0;
        n = reverseBinNum(n);
    }
    for(int i = 0; i < n; i++)
    {
        fread(&num, sizeof(int), 1, input);
        if (!isLittleEndian)
            num = reverseBinNum(num);
        res+=num;
    }
    if(!isLittleEndian)
        res = reverseBinNum(res);
    fwrite(&res, sizeof(int), 1, output);
    fclose(input);
    fclose(output);
    return 0;
}

