#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define MAX_LEN 500100

int getPriorityOfChar(char c)
{
    switch (c)
    {
        case '(':
            return 1;
        case ')':
            return 2;
        case '=':
            return 3;
        case '+':
        case '-':
            return 4;
        case '*':
        case '/':
            return 5;
        case '?':
            return 6;
        default:
            return -1;
    }
}

void deleteWhitespaces(char *oldString, char *newString)
{
    int i = 0, j = 0;
    while (oldString[i] != '\0')
    {
        if (oldString[i] != ' ')
        {
            newString[j] = oldString[i];
            j++;
        }
        i++;
    }
    newString[j] = 0;
}

void InfixToPostfix(char *infixString, char *postfixString)
{
    char x, c;
    int index = 0, priority, i = 0;
    stack *s = createNewStack();
    while (infixString[i] != '\0')
    {
       x = infixString[i];
       if ((x >= '0') && (x <= '9'))
       {
           postfixString[index] = x;
           index++;
       }
       else if (x == '('){
            postfixString[index] = ' ';
            index++;
            pushToStack(x, s);
       }
       else if (x == ')')
       {
           postfixString[index] = ' ';
           index++;
           while (getTopOfStack(s) != '(')
           {
               postfixString[index] = popFromStack(s);
               index++;
           }
           popFromStack(s);
       }
       else
       {
           postfixString[index] = ' ';
           index++;
           if ((i == 0) || (infixString[i-1] == '('))
           {
               pushToStack('?', s);
               i++;
               continue;
           }
           priority = getPriorityOfChar(x);
           while (!(isStackEmpty(s)) && (getPriorityOfChar(getTopOfStack(s)) >= priority))
           {
                c = popFromStack(s);
                postfixString[index] = c;
                index++;
           }
           postfixString[index] = ' ';
           index++;
           pushToStack(x, s);
       }
       i++;
    }

    while (!isStackEmpty(s))
    {
        postfixString[index] = ' ';
        index++;
        postfixString[index] = popFromStack(s);
        index++;
    }

    postfixString[index] = 0;
}

long double calculateOperation(long double operand1, long double operand2, char operation)
{
    switch(operation)
    {
        case '+':
            return 1.0*operand1+operand2;
        case '?':
        case '-':
            return 1.0*operand1-operand2;
        case '*':
            return 1.0*operand1*operand2;
        case '/':
        {
            if (operand2 == 0)
            {
                printf("Error: division by zero\n");
                exit(-1);
            }
            return 1.0*operand1/operand2;
        }
        default:
        {
            printf("Error: unknown operation\n");
            exit(-1);
        }
    }
}

long double calculatePostfix(char *postfixString)
{
    long double intermediateResult, operand1, operand2;
    int i = 0;
    stack *s = createNewStack();
    while (postfixString[i] != '\0')
    {
        if  ((postfixString[i] >= '0') && (postfixString[i] <= '9'))
        {
            char numFromString[20] = {0};
            int index = 0;
            int tmp;
            while ((postfixString[i] >= '0') && (postfixString[i] <= '9'))
            {
                numFromString[index] = postfixString[i];
                index++;
                i++;
            }
            numFromString[index] = 0;
            tmp = atoi(numFromString);
            pushToStack(1.0*tmp, s);
        }
        else if (postfixString[i] != ' ')
        {
            operand2 = popFromStack(s);
            if (postfixString[i] != '?')
                operand1 = popFromStack(s);
            else
                operand1 = 0;
            intermediateResult = calculateOperation(operand1, operand2, postfixString[i]);
            pushToStack(intermediateResult, s);
            i++;
        }
        else
            i++;
    }
    return popFromStack(s);
}

long double getResult()
{
    long double res;
    char *inp = malloc(MAX_LEN*sizeof(char));
    char *infixString = malloc(MAX_LEN*sizeof(char));
    char *postfString = malloc((2*MAX_LEN+1)*sizeof(char));
    gets(inp);
    deleteWhitespaces(inp, infixString);
    InfixToPostfix(infixString, postfString);
    res = calculatePostfix(postfString);
    free(inp);
    free(infixString);
    free(postfString);
    return res;
}

#include "calculations.h"
