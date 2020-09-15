#include <stdio.h>
#define N 1001
#define M 3

void PrintTableString(int lenCol[], FILE *out)
{
    for (int j = 0; j < 3; j++)
    {
        fprintf(out, "+-");
        for(int i = 0; i < lenCol[j]+1; i++)
            fprintf(out, "-");
    }
    fprintf(out, "+\n");
}

void PrintTableNums(int lenCol[], int frag[], FILE *out)
{
    for (int j = 0; j < M; j++)
    {
        fprintf(out, "| ");
        for(int d = 0; d < (lenCol[j] - CountOfDigigts(frag[j]) ); d++)
            fprintf(out, " ");
        fprintf(out, "%d ", frag[j]);
    }
    fprintf(out, "|\n");
}

int CountOfDigigts(int num)
{
    int result = 0;
    while (num > 0)
    {
        num/=10;
        result++;
    }
    return result;
}

int main()
{
    FILE *input;
	FILE *output;
	input = fopen("input.txt", "r");
	output = fopen("output.txt", "w");
    int fragments[N][M] = {{0}, {0}, {0}};
    int mId = 0;
    int mSum = 0;
    int mCount = 0, id, length, n;
    int lenCol[M];
    fscanf(input, "%d", &n);
    for(int i = 0; i < n; i++)
    {
        fscanf(input, "%d%d", &id, &length);
        fragments[id][0] = id;
        fragments[id][1]++;
        fragments[id][2]+=length;
        if (id > mId)
            mId = id;
        if (fragments[id][1] > mCount)
            mCount = fragments[id][1];
        if (fragments[id][2] > mSum)
            mSum = fragments[id][2];
    }
    lenCol[0] = CountOfDigigts(mId);
    lenCol[1] = CountOfDigigts(mCount);
    lenCol[2] = CountOfDigigts(mSum);
    PrintTableString(lenCol, output);
    for(int i = 1; i <= mId; i++)
    {
        if (fragments[i][1]!=0)
        {
            PrintTableNums(lenCol, fragments[i], output);
            PrintTableString(lenCol, output);
        }
    }
    fclose(output);
    fclose(input);
	return 0;
}

