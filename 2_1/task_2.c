#include <stdio.h>
#include <stdlib.h>

typedef struct list_s {
    int data;
    struct list* next;
}list;

typedef struct stack_s { list *top; } stack;

stack* createNewStack()
{
    stack* S;
    S = malloc(sizeof (stack));
    S->top = NULL;
    return S;
}

int getTopOfStack(stack *S)
{
    if (S->top)
        return (S->top->data);
    return 0;
}

int popFromStack(stack *S)
{
    int a;
    list *p;
    p = S->top;
    if (p)
    {
        a = p->data;
        S->top = p->next;
        free(p);
        return a;
    }
    return 0;
}

void pushToStack(int a, stack *S)
{
    list *p;
    p = malloc(sizeof(list));
    p->data = a;
    p->next = S->top;
    S->top = p;
}

int isStackEmpty(stack *s)
{
    return (s->top == NULL);
}

int calculateOperation(int operand1, int operand2, char operation)
{
    switch(operation)
    {
        case '+':
            return operand1+operand2;
        case '-':
            return operand1-operand2;
        case '*':
            return operand1*operand2;
        case '/':
            return operand1/operand2;
        default:
            return -1;
    }
}

int calculatePostfixFromInput()
{
    int intermediateResult, operand1, operand2;
    char x[10];
    stack *s = createNewStack();
    while (scanf("%s ", x) != EOF)
    {
        if ((x[0] >= '0') && (x[0] <= '9'))
        {
            pushToStack(atoi(x), s);
        }
        else
        {
            operand2 = popFromStack(s);
            operand1 = popFromStack(s);
            intermediateResult = calculateOperation(operand1, operand2, x[0]);
            pushToStack(intermediateResult, s);
        }
    }
    return popFromStack(s);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int result = calculatePostfixFromInput();
    printf("%d", result);
    return 0;
}

