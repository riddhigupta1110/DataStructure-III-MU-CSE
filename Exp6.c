#include<stdio.h>
#include<stdlib.h>
int count = 0;
struct node{
    int data;
    struct node *next;
}*head, *newNode, *t, *prev;
void initialiseHead()
{
    head = NULL;
}
void display()
{
    printf("\n");
    t = head;
    while(t!=NULL){
        printf("%d ", t->data);
        t = t -> next;
    }
}
void insertStart()
{
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data: ");
    scanf("%d", &newNode->data);
    newNode->next = head;
    head = newNode;
    count++;
}
void insertEnd()
{
    t = head;
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if(head==NULL)
        head = newNode;
    else{
        while(t->next!=NULL){
            t = t->next;
        }
        t->next = newNode;
    }
    count++;
}
void insertCustom()
{
    int val, v;
    t = head;
    if(t==NULL){
        printf("\nEmpty Linked List!");
        return;
    }
    else{
        printf("Enter value after which NODE is to be inserted:  ");
        scanf("%d", &val);
        newNode = (struct node*)malloc(sizeof(struct node));
        prev = head;
        if(t->next!=NULL){
            if(t->data==val){
                    printf("\nEnter value to be inserted: ");
                    scanf("%d", &newNode->data);
                    newNode->next = t->next;
                    t->next = newNode;
                    return;
                }
            t = t->next;
            while(t->next!=NULL){
                if(t->data==val){
                    printf("\nEnter value to be inserted: ");
                    scanf("%d", &newNode->data);
                    newNode->next = t->next;
                    t->next = newNode;
                    return;
                }
                prev = t;
                t = t->next;
            }
            if(t->data==val){
                    printf("\nEnter value to be inserted: ");
                    scanf("%d", &newNode->data);
                    newNode->next = t->next;
                    t->next = newNode;
                    return;
                }
        }
        else{
            if(t->data==val){
                printf("\nEnter value to be inserted: ");
                scanf("%d", &newNode->data);
                newNode->next = NULL;
                t->next = newNode;
                return;
            }
            else{
                printf("\nNo such node present!");
                return;
            }
        }
    }
    printf("\nNo such node present");
}
void deleteStart()
{
    t = head;
    if(t==NULL)
        printf("\nEmpty Lined List!");
    else{
        printf("\nRemoved: ", t->data);
        head = t->next;
        free(t);
        count--;
    }
}
void deleteEnd()
{
    if(head==NULL)
        printf("\nEmpty Lined List!");
    else{
        t = prev = head;
        if(t->next!=NULL){
            t= t->next;
            while(t->next!=NULL){
                prev = t;
                t = t->next;
            }
            printf("\nRemoved: ", t->data);
            free(t);
            prev->next = NULL;
        }
        else{
            printf("\nRemoved: ", t->data);
            free(t);
            head = NULL;
        }
    }
}
void deleteCustom()
{
    int val;
    t = head;
    if(t == NULL){
        printf("\nEmpty Linked list!");
        return;
    }
    else{
        printf("\nEnter value of the node to be deleted: ");
        scanf("%d", &val);
        prev = head;
        if(t->next!=NULL){
            if(t->data==val){
                head = t->next;
                free(t);
                return;
            }
            t = t->next;
            while(t->next!=NULL){
                if(t->data==val){
                    prev->next = t->next;
                    free(t);
                    return;
                }
                prev = t;
                t = t->next;
            }
            if(t->data==val){
                prev->next = NULL;
                free(t);
                return;
            }
        }
        else{
            if(t->data==val){
                free(t);
                head = NULL;
                return;
            }
            else{
                printf("\nNo such node present!");
                return;
            }
        }
    }
    printf("\nNo such node present!");
}
void main()
{
    initialiseHead();
    insertEnd();
    insertEnd();
    insertEnd();
    insertEnd();
    deleteCustom();
    display();
}
