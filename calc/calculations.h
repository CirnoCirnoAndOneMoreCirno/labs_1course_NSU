#ifndef CALCULATIONS_H_INCLUDED
#define CALCULATIONS_H_INCLUDED

long double getResult();
int getPriorityOfChar(char c);
void deleteWhitespaces(char *oldString, char *newString);
void InfixToPostfix(char *infixString, char *postfixString);
long double calculateOperation(long double operand1, long double operand2, char operation);
long double calculatePostfix(char *postfixString);

#endif // CALCULATIONS_H_INCLUDED
