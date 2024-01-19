#include <stdio.h>
#include<stdlib.h>
//create tree data
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
//function for cteate tree
node* createTree(node* root){
    int data;
    printf("Enter the data for node : ");
    scanf("%d",&data);
    if(data == -1){
        return NULL;
    }
    root = createNode(data);
    root->left = createTree(root->left);
    root->right= createTree(root->right);
    return root;
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
void preorder(node* root){
    if(root == NULL){
        return;
    }
    printf("%d ",root->data);
    inorder(root->left);
    inorder(root->right);
}
void postorder(node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
void main(){
    node* root;
    root = createTree(root);
    printf("inorder : ");
    inorder(root);
    printf("\npreorder : ");
    preorder(root);
    printf("\npostorder : ");
    postorder(root);
}
