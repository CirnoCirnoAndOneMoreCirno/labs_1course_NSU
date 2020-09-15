#include <stdio.h>

typedef struct list_s {
    char data;
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
    char a;
    list *p;
    p = S->top;
    if (p)
    {
        a = p->data;
        S->top = p->next;
        free(p);
        return a;
    }
    return 257;
}

void pushToStack(char a, stack *S)
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

int getPriorityOfChar(char c)
{
    switch (c)
    {
        case '(':
        {
            return 1;
            break;
        }
        case ')':
        {
            return 2;
            break;
        }
        case '=':
        {
           return 3;
           break;
        }
        case '+':
        {
            return 4;
            break;
        }
        case '-':
        {
            return 4;
            break;
        }
        case '*':
        {
            return 5;
            break;
        }
        case '/':
        {
            return 5;
            break;
        }
        default:
            break;
    }
}

void InfixToPostfixFromInput(char *postfixString)
{
    char x;
    int index = 0, priority;
    stack *s = createNewStack();
    while (scanf("%c", &x) != EOF)
    {
       if ((x >= 'a') && (x <= 'z'))
       {
           postfixString[index] = x;
           index++;
       }
       else if (x == '(')
          pushToStack(x, s);
       else if (x == ')')
       {
           while (getTopOfStack(s) != '(')
           {
               postfixString[index] = popFromStack(s);
               index++;
           }
           popFromStack(s);
       }
       else
       {
           priority = getPriorityOfChar(x);
           while (!(isStackEmpty(s)) && (getPriorityOfChar(getTopOfStack(s)) >= priority))
           {
               postfixString[index] = popFromStack(s);
               index++;
           }
           pushToStack(x, s);
       }
    }

    while (!isStackEmpty(s))
    {
        postfixString[index] = popFromStack(s);
        index++;
    }

    postfixString[index] = 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char  postfString[1001];
    InfixToPostfixFromInput(postfString);
    printf("%s", postfString);
    return 0;
}
