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
void enqueue(int val)
{
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    if(head==NULL){
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
int dequeue()
{
   int val = -1;
   if(head==NULL){

   }
   else{
        t = head;
        head = t->next;
        val = t->data;
        free(t);
   }
   return val;
}
void bfs()
{
    int i, j=0,temp, val=0;
    enqueue(0);
    visited[0] = 1;
    while(check()==1){
        j = dequeue();
        printf("%d ", j);
        for(i=0; i<5; i++){
            if(matrix[j][i]==1 && visited[i]==0){
                enqueue(i);
                visited[i] = 1;
            }
        }

    }
    while(val!=-1){
        val = dequeue();
        if(val!=-1)
            printf("%d ", val);
    }

}
void main()
{
    bfs();

}
