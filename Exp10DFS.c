#include<stdio.h>
#include<stdlib.h>
int matrix[5][5]={{0,1,1,1,0},{1,0,1,0,0},{1,1,0,0,1},{1,0,0,0,0},{0,0,1,0,0}};
int visited[5] = {0,0,0,0,0};
struct node{
    int data;
    struct node *next;
}*head, *t, *prev, *newNode;
void initialiseHead()
{
    head = NULL;
}
int check()
{
    int i;
    for(i=0; i<5; i++){
        if(visited[i]==0)
            return 1;
    }
    return 0;
}
void push(int val)
{
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next=NULL;
    if(head == NULL){
        head = newNode;
    }
    else{
        t = head;
        while(t->next!=NULL){
            t = t->next;
        }
        t->next = newNode;
    }
}
int pop()
{
    int val = -1;
    if(head==NULL){
        //printf("\nEmpty Linked List!\n");

    }
    else{
        t = head;
        if(t->next==NULL){
            val = (t->data);
            head = NULL;
            free(t);
        }
        else{
            prev  = t;
            t = t->next;
            while(t->next!=NULL){
                prev  = t;
                t = t->next;
            }
            val = (t->data);
            prev->next = NULL;
            free(t);
        }
    }
    return val;
}
void display()
{
    printf("\n Displaying:");
    t = head;
    while(t!=NULL){
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}
void dfs()
{
    int i, j=0,temp, val=0;
    push(0);
    visited[0] = 1;
    while(check()==1){
        j = pop();
        printf("%d ", j);
        for(i=0; i<5; i++){
            if(matrix[j][i]==1 && visited[i]==0){
                push(i);
                visited[i] = 1;
            }
        }

    }
    while(val!=-1){
        val = pop();
        if(val!=-1)
            printf("%d ", val);
    }

}
void main()
{
    dfs();

}
