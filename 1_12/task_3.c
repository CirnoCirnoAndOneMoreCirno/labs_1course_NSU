#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, operationId, length, index, stringsCount = 0, symbolCount;
    char symbol;
    scanf("%d", &n);

    char **strings = malloc(n * sizeof(char *));

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &operationId);
        switch(operationId)
        {
        case 0:
            {
                scanf("%d", &length);
                strings[stringsCount] = malloc((length+1) * (sizeof(char)));
                scanf("%s", strings[stringsCount]);
                stringsCount++;
                break;
            }
        case 1:
            {
                scanf("%d", &index);
                free(strings[index]);
                strings[index] = NULL;
                break;
            }
        case 2:
            {
                scanf("%d", &index);
                printf("%s\n", strings[index]);
                break;
            }
        case 3:
            {
                scanf("%d %c", &index, &symbol);
                symbolCount = 0;
                int j = 0;
                while (strings[index][j] != '\0')
                {
                    if (strings[index][j] == symbol)
                        symbolCount++;
                    j++;
                }
                printf("%d\n", symbolCount);
                break;
            }
        default:
            break;
        }
    }

    for(int i = 0; i < stringsCount; i++)
    {
        if (strings[i] != NULL)
        {
            free(strings[i]);
            strings[i] = NULL;
        }
    }

    free(strings);

    return 0;
}

