#include <stdio.h>
#include <stdlib.h>

typedef struct list_s {
    long double data;
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

long double getTopOfStack(stack *S)
{
    if (S->top)
        return (S->top->data);
    return 0;
}

long double popFromStack(stack *S)
{
    long double a;
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

void pushToStack(long double a, stack *S)
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

#include "stack.h"
