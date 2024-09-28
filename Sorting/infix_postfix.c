#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char stack[MAX], infix[MAX], postfix[MAX];
int top = -1;

void print()
{
    for (int i = 0; i < strlen(infix); i++)
        printf("%c ", postfix[i]);
        printf("\n");
}

void push(char val)
{
    top++;
    stack[top] = val;
}

char pop()
{
    int val = stack[top];
    top = top - 1;
    return val;
}

int isempty()                //to check emptiness and to pop all values which are in stack after '('  
{
    if (top == -1)
        return 1;
    else             
        return 0;
}

int precedence(char val)    //precedence will decide whether stack top element shoud be included in postfix or not
{
    if (val == '^')
        return 3;
    else if (val == '*' || val == '/')
        return 2;
    else if (val == '+' || val == '-')
        return 1;
    else
        return 0;
}

void intopost()
{
    int j = 0;
    char next, symbol;
    for (int i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];

        if (symbol == '(')
        {
            push(symbol);
        }
        else if (symbol == ')')
        {
            while ((next = pop()) != '(')
                postfix[j++] = next;
        }
        else if (symbol == '+' || symbol == '-' || symbol == '^' || symbol == '*' || symbol == '/')
        {
            while (!isempty() && precedence(stack[top]) >= precedence(symbol))
                postfix[j++] = pop();
            push(symbol);
        }

        else
        {
            postfix[j++] = symbol;              //Remember these
        }
    }
    while (!isempty())                          //rem these
        postfix[j++] = pop();
}

int main()
{
    scanf("%s", infix);

    intopost();
    print();
    return 0;
}
