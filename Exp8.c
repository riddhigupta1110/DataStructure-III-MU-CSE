#include<stdio.h>
#include<stdlib.h>
int top=-1;
struct node{
    int data;
    struct node *next;
}*head, *newNode, *t, *prev;
void initialiseHead()
{
    head = NULL;
}
void push()
{
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter value: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if(head==NULL){
        head = newNode;
        top++;
        return;
    }
    else{
        t = head;
        while(t->next!=NULL){
            t = t->next;
        }
        t->next = newNode;
    }
    top++;
    return;
}
void pop()
{
    t = head;
    if(t == NULL){
        printf("\nEmpty Linked List");
        return;
    }
    else{
        if(t->next == NULL){
            head = NULL;
            free(t);
            top--;
            return;
        }
        else{
            prev = head;
            t = t->next;
            while(t->next!=NULL){
                prev = t;
                t = t->next;
            }
            prev->next = NULL;
            free(t);
        }
        top--;
        return;
    }
}
void display()
{
    printf("\n");
    t = head;
    while(t!=NULL){
        printf("%d ", t->data);
        t = t->next;
    }
    return;
}
void main()
{
        initialiseHead();
        push();
        push();
        push();
        display();
        pop();
        display();
}
