#include <stdio.h>
#include<stdlib.h>
//create tree then make mirror tree 
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
        return ;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
//function for mirror tree
node* mirror(node* root){
    if(root == NULL){
        return 0;
    }
    node* temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;
    //mirror for left subtree
    root->left= mirror(root->left);
    //mirrot for right subtree
    root->right=mirror(root->right);
    return root;
}
void main(){
    node* root;
    root = createTree(root);
    printf("inorder : ");
    inorder(root);
    mirror(root);
    printf("\nMirrot tree inorder : ");
    inorder(root);
}

