#include<stdio.h>
#define MAX 10
#include<string.h>
#include<ctype.h>
int top=-1, j=0, i;
char stack[MAX];
char infix[MAX], postfix[MAX];

void push(char c)
{
    if(top==MAX-1)
        printf("\nStack overflow");
    else
        stack[++top] = c;
}
char pop()
{
    if(top==-1)
        return '>';
    else
        return (stack[top--]);
}
int getPriority(char c1)
{
    if(c1 == "/" || c1 =='%' || c1 =="*" )
        return 2;
    else if(c1=='+' || c1=='-')
        return 1;
    else if(c1=='(' )
        return 0;
    return 9;
}
void infixToPostfix()
{
    char temp;
    i=0;
    while(infix[i]!='\0')
    {
        char ch = infix[i];
        if(ch=='(')
            push(ch);
        else if(isalnum(ch))
            postfix[j++] = ch;
        else if(ch==')')
        {
            while(stack[top]!=')' && top!=-1)
            {
                postfix[j++] = pop();
            }
            temp = pop();
        }
        else{
            while(getPriority(ch)<= getPriority(stack[top]))
            {
                postfix[j++] = pop();
            }
            push(ch);
        }
        i++;
    }
}
void main()
{
    int t=0;
    printf("Enter a infix expression: ");
    scanf("%s", infix);
    stack[top++] = '(';
    strcat(infix, ")");
    infixToPostfix();
    for(t=0; t<j; t++)
        printf("%c", postfix[t]);
}
