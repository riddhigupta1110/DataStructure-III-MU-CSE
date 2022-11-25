#include<stdio.h>
#define MAX 3
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int val)
{
    if(front==-1 && rear==-1){
        front = rear = 0;
        queue[rear] = val;
    }
    else if(((rear+1)%MAX)==front){
        printf("\nQueue is full!");
    }
    else{
        rear = (rear+1)%MAX;
        queue[rear] = val;
    }
}
void dequeue()
{
    if(front==-1 && rear==-1){
        printf("\nQueue is empty!");
    }
    else if(front==rear){
        printf("%d", queue[front]);
        front = rear = -1;
    }
    else{
        printf("%d", queue[front]);
        front = (front+1)%MAX;
    }
}
void display()
{
    printf("\n");
    int i = front;
    while(i!=rear){
        printf("%d ", queue[i]);
        i = (i+1)%MAX;
    }
    printf("%d", queue[rear]);
}
void main()
{
    enqueue(5);
    enqueue(4);
    enqueue(3);
    dequeue();
    enqueue(2);
    display();
}
