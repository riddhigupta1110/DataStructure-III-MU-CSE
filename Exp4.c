#include<stdio.h>
#define MAX 2
int queue[MAX];
int front, rear;
front = -1;
rear = -1;
void display()
{
    int i;
    printf("\n");
    for(i=front; i<=rear; i++){
        printf("%d ", queue[i]);
    }
}
void enqueue(int val)
{
    if(front==-1 && rear==-1){
        front = rear = 0;
        queue[rear] = val;
    }
    else if(rear==MAX-1){
        printf("\nQueue is full!");
    }
    else{
        queue[++rear] = val;
    }
}
void dequeue()
{
    if(front==-1 && rear==-1){
        printf("\nQueue is empty!");
    }
    else if(front == MAX){
        printf("\nQueue is empty!");
    }
    else{
        printf("\nDequeued: %d", queue[front++]);
    }
}
void main()
{
    enqueue(5);
    enqueue(4);
    display();
    dequeue();
    dequeue();
    display();
    dequeue();
}
