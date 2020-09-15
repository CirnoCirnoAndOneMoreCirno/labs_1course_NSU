#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct list_s list;
typedef struct stack_s stack;

stack* createNewStack();
long double getTopOfStack(stack *S);
long double popFromStack(stack *S);
void pushToStack(long double a, stack *S);
int isStackEmpty(stack *s);


#endif // STACK_H_INCLUDED
