#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left, *right;
}*root, *newNode, *t, *t1;
void createTree()
{
    root = NULL;
}
void insert(int val)
{
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    if(root==NULL){
        root = newNode;
    }
    else{
         t = t1 = root;
         while(t!=NULL){
                t1 = t;
            if(val<t->data){
                t = t->left;
            }
            else{
                t = t->right;
            }
         }
         if(val<t1->data)
            t1->left = newNode;
         else
            t1->right = newNode;
    }
}
void inorder(struct node *n)
{
    if(n!=NULL){
        inorder(n->left);
        printf("%d ", n->data);
        inorder(n->right);
    }
}
void preorder(struct node *n)
{
    if(n!=NULL){
        printf("%d ", n->data);
        inorder(n->left);
        inorder(n->right);
    }
}
void postorder(struct node *n)
{
    if(n!=NULL){
        inorder(n->left);
        inorder(n->right);
        printf("%d ", n->data);
    }
}
struct node* smallest( struct node *n)
{
    if(n==NULL||n->left==NULL)
        return n;
    else
        return smallest(n->left);
}
struct node *largest(struct node *n)
{
    if(n==NULL||n->right==NULL)
        return n;
    else
        return largest(n->right);

}
int totalNode(struct node *n)
{
    if(n==NULL)
        return 0;
    else
        return (totalNode(n->left) + totalNode(n->right)+1);
}
int externalNode(struct node* n)
{
    if(n==NULL)
        return 0;
    else if(n->right==NULL && n->left==NULL)
        return 1;
    else
        return (externalNode(n->left)+externalNode(n->right));
}
int internalNode(struct node* n)
{
    if(n==NULL)
        return 0;
    else if(n->right==NULL && n->left==NULL)
        return 0;
    else
        return(internalNode(n->left)+internalNode(n->right)+1);
}
int height(struct node *n)
{
    int leftHeight, rightHeight;
    if(n==NULL)
        return 0;
    else{
        leftHeight = height(n->left);
        rightHeight = height(n->right);
        if(leftHeight>rightHeight)
            return(leftHeight+1);
        else
            return(rightHeight+1);
    }
}
void mirror(struct node *n)
{
    struct node *ptr;
    if(n!=NULL){
        mirror(n->left);
        mirror(n->right);
        ptr = n->left;
        n->left = n->right;
        n->right = ptr;
    }
}
struct node* minValueNode(struct node* n)
{
    struct node* current = n;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
struct node* delete(struct node *n, int val)
{
    if(n==NULL){
        return n;
    }
    if(val<n->data)
        n->left = delete(n->left, val);
    else if(val>n->data)
        n->right = delete(n->right, val);
    else{
        if(n->left == NULL){
            struct node *temp = n->right;
            free(n);
            return temp;
        }
        else if(n->right == NULL){
            struct node *temp = n->left;
            free(n);
            return temp;
        }
        struct node *temp = minValueNode(n->right);
        n->data = temp->data;
        n->right = delete(n->right, temp->data);
    }
    return root;
}
int main()
{
    createTree();
    insert(50);
    insert(30);
    insert(70);
    insert(20);
    insert(40);
    insert(60);
    insert(80);
    inorder(root);
    t = smallest(root);
    printf("\nSmallest: %d", t->data);
    t = largest(root);
    printf("\nLargest: %d", t->data);
    int numN = totalNode(root);
    printf("\nNumber of node: %d", numN);
    numN = internalNode(root);
    printf("\nNumber of internal node: %d", numN-1);
    numN = externalNode(root);
    printf("\nNumber of external node: %d", numN);
    int h = height(root);
    printf("\nHeight: %d", h);
    //mirror(root);
    printf("\n");
    inorder(root);
    root = delete(root, 20);
    printf("\nI came here!");
    inorder(root);
    printf("\nI came here!");
    return 0;
}
