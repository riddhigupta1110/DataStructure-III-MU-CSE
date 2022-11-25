#include<stdio.h>
#define MAX 10
int stack[MAX];
char postfix[MAX];
int top=-1;
int i;

void push(int ch)
{
    if(top==MAX-1)
        printf("Stack overflow");
    else
        stack[++top] = ch;
}
char pop()
{
    if(top==-1)
            return 0;
    else
        return stack[top--];
}
evaluatePostfix()
{
    i=0;
    while(postfix[i]!=')')
    {
        char ch = postfix[i];
        if(isdigit(ch))
        {
            int ch1 = ((int)ch )- 48;
            push(ch1);
        }
        else{
            int b = pop();
            int a = pop();
            switch(ch)
            {
            case'+':
                stack[++top] = a + (b);
                break;
            case'-':
                stack[++top] = (a) - (b);
                break;
            case'/':
                stack[++top] = (a) / (b);
                break;
            case'*':
                stack[++top] = (a) * (b);
                break;
            case'%':
                stack[++top] = (a) % (b);
                break;
            default:
                printf("\nIncorrect operator\n");
            }
        }
        i++;
    }
}
void main()
{
        printf("Enter a postfix expression: ");
        scanf("%s", &postfix);
        stack[++top] = "(";
        strcat(postfix, ")");
        evaluatePostfix();
        printf("%d", (stack[top]));
}
