#include<stdio.h>
#include<stdlib.h>
int count = 0;
struct node{
    int data;
    struct node *next;
}*head, *t, *prev, *newNode, *t1;
void initialisehead()
{
    head = NULL;
}
void insertBeginning(int val)
{
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    if(head==NULL){
        head = newNode;
        newNode->next = head;
    }
    else{
        t = head;
        while(t->next!=head){
            t = t->next;
        }
        t->next = newNode;
        newNode->next = head;
        head = newNode;
        printf("\nExiting!!");
    }
    count++;
}
void insertEnd(int val)
{
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    t = head;
    if(t==NULL){
        head = newNode;
        newNode->next = head;
    }
    else{
        while(t->next!=head){
            t = t->next;
        }
        t->next = newNode;
        newNode->next = head;
    }
    count++;
}
void insertCustom(int val)
{
    if(head == NULL){
        printf("\nNo such value found!");
    }
    else{
        newNode = (struct node*)malloc(sizeof(struct node));
        t = head;
        while(t->next!=head){
            if(t->data==val){
                printf("\nEnter value of new node: ");
                scanf("%d",&newNode->data);
                newNode->next = t->next;
                t->next = newNode;
                count++;
                return;
            }
            t = t->next;
        }
        if(t->data == val){
            printf("\nEnter value of new node: ");
            scanf("%d",&newNode->data);
            newNode->next = head;
            t->next = newNode;
            count++;
        }
    }
}
void deleteEnd()
{
    if(head==NULL){
        printf("\nEmpty Linked List!");
    }
    else{
        t = t1 = head;
        if(t->next==head){
            head = NULL;
            free(t);
        }
        else{
            t = t->next;
            while(t->next!=head){
                t1 = t;
                t = t->next;
            }
            t1->next = head;
            free(t);
        }
        count--;
    }
}
void deleteStart()
{
    if(head==NULL){
        printf("\nEmpty Linked List!");
    }
    else{
        t = head;prev = head;
        if(t->next!=head){
            t = t->next;
            t1 = head;
            while(t1->next!=head){
                t1 = t1->next;
            }
            t1->next = t;
            head = t;
            free(prev);
        }
        else{
            head = NULL;
            free(t);
        }
    }
    count--;
}
void deleteCustom(int val)
{
    if(head == NULL){
        printf("\nEmpty Linked List!");
    }
    else{
        t = head;
        if(t->next==head && t->data==val){
            head = NULL;
            free(t);
            count--;
        }
        else{
            t = t->next;
            prev = head;
            while(t->next!=head){
                if(t->data==val){
                    prev->next = t->next;
                    free(t);
                    count--;
                    return;
                }
                prev = t;
                t = t->next;
            }
            if(t->data==val){
                prev->next = NULL;
                free(t);
                count--;
            }
        }
    }
}
void display()
{
    printf("\nList: ");
    t = head;
    while(t->next!=head){
        printf("%d ", t->data);
        t = t->next;
    }
    printf("%d ", t->data);
}
void main()
{
    initialisehead();
    insertEnd(5);
    display();
    insertEnd(4);
    insertBeginning(3);
    insertCustom(5);
    display();
}
