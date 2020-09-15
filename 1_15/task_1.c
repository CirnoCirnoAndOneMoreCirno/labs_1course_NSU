#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *input = fopen("input.bin", "rb");
    FILE *output = fopen("output.bin", "wb");
    int num1, num2, q;
    long long num3;
    fread(&num1, sizeof(int), 1, input);
    fread(&num2, sizeof(int), 1, input);
    num3 = (1LL*num1 + num2) / 2;
    if ((num3 <= 0) && ((1LL*num1 + num2)%2))
        num3--;
    q = num3;
    fwrite(&q, sizeof(int), 1, output);
    return 0;
}

