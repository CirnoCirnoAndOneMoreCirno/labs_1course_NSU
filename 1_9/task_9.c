#include <stdio.h>
#include <string.h>

int main()
{
    FILE *input;
	FILE *output;
	input = fopen("input.txt", "r");
	output = fopen("output.txt", "w");
	char curr = 0, chBefore = 0;
	char isComm1 = 0;
	char isComm2 = 0;
	while (1)
    {
        if ((((chBefore == '/') && (curr != '/') && (curr != '*')) || ((chBefore == '*') && (curr != '/'))) && (!isComm1) && (!isComm2))
            fprintf(output, "%c", chBefore);
        if (fscanf(input, "%c", &curr) != 1)
            break;
        if ((curr == '/') && (chBefore == '/'))
            isComm1 = 1;
        else if (curr == '\n')
            isComm1 = 0;
        if ((chBefore == '/') && (curr == '*'))
            isComm2 = 1;
        else if ((chBefore == '*') && (curr == '/'))
            isComm2 = 0;
        chBefore = curr;
        if (((!isComm1) && (!isComm2) &&  (curr != '/') && (curr != '*')) || (curr == '\n'))
            fprintf(output, "%c", curr);
    }
    fclose(input);
	fclose(output);
    return 0;
}
