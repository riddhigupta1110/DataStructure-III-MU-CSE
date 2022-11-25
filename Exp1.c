#include<stdio.h>
#define MAX 5
int arr[MAX];
int top=-1;
void display()
{
    int i;
    for(i=top; i>=0; i--){
        printf("\n%d ", arr[i]);
    }
}
void peek()
{
    if(top==-1)
        printf("\nStack is empty");
    else{
        printf("\n%d", arr[top]);
    }
}
void push(int val)
{
    if(top==MAX-1)
        printf("\nStack overflow");
    else{
        arr[++top] = val;
    }
}
void pop()
{
    if(top==-1)
        printf("\nStack Undeflow");
    else{
        printf("\nPopped: %d", arr[top]);
        top--;
    }
}
void main()
{
    int choice, val;
    printf("\n1 - Push\n2 - Pop\n3 - Display\n4 - Peek\n5 - Exit");
    do
    {
        printf("\nEnter a choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("\nEnter a value: ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            return;
        default:
            printf("Wrong choice!");
        }
    }
    while(choice!=5);
}
