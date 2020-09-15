#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculations.h"
#include "stack.h"
#define MAX_LEN 500100

void help()
{
    printf("Please, indicate the path to input and output text files with -i file_name and -o file_name\n");
    printf("If you want to use console, you should write -i/-o console (use lowercase!)");
    exit(-1);
}

int main(int argc, char **args)
{
    if (argc == 1)
    {
        help();
    }
    char *input = NULL;
    char *output = NULL;
    for(int i = 1; i < argc; i++)
    {
        if (strcmp(args[i], "-i") == 0)
        {
            input = args[i+1];
        }
        if (strcmp(args[i], "-o") == 0)
        {
            output = args[i+1];
        }
    }
    if (input == NULL)
        help();
    if (output == NULL)
        help();
    if (strcmp(input, "console") != 0)
        freopen(input, "r", stdin);
    if (strcmp(output, "console") != 0)
        freopen(output, "w", stdout);
    long double res = getResult();
    printf("%.20lf\n", (double)res);
    return 0;
}

