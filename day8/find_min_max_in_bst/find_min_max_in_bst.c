#include <stdio.h>
#include<stdlib.h>
//create Binary search tree and find min and max of BST
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;
//function for cteate tree node 
node* createNode(int data){
    node* new = malloc(sizeof(node));
    new->data = data;
    new->left = NULL;
    new->right=NULL;
    return new;
}
//function for insert data in binary tree
node* insert_BST(node* root, int data){
    if(root == NULL){
        root = createNode(data);
    }
    else{
        if(root->data >= data){
            root->left = insert_BST(root->left, data);
        }
        else{
            root->right=insert_BST(root->right,data);
        }
    }
    return root;
}
//function for take input to make BST
node* takeinput(node* root){
    int data;
    printf("Enter the data for node : ");
    scanf("%d",&data);
    while(data != -1){
        root = insert_BST(root,data);
        printf("Enter the data for node : ");
        scanf("%d",&data);
    }
    return root;
}
//function for find min
int findMin(node* root){
    if(root->left == NULL){
        return root->data;
    }
    findMin(root->left);
}
//function for find max
int findMax(node* root){
    if(root->right == NULL){
        return root->data;
    }
    findMax(root->right);
}
//function for traverse the tree method 
//inorder (L Root R), preoredr (Root L R), postorder(L R Root)
void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void main(){
    node* root;
    root = takeinput(root);
    printf("inorder : ");
    inorder(root);
    int min = findMin(root);
    printf("\nMin = %d",min);
    int max = findMax(root);
    printf("\nMax = %d",max);
}

