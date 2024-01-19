#include <stdio.h>
#include<stdlib.h>
//create Binary search tree perform delection operation in the BST
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
    int data,x=-1;
    printf("Enter the data for node : ");
    scanf("%d",&data);
    while(data != x){
        root = insert_BST(root,data);
        printf("Enter the data for node : ");
        scanf("%d",&data);
    }
    return root;
}
//function for find min
node* findMin(node* root){
    if(root->left == NULL){
        return root;
    }
    findMin(root->left);
}
//function for find max
node* findMax(node* root){
    if(root->right == NULL){
        return root;
    }
    findMax(root->right);
}
//function for deletion 
node* delete(node* root,int del){
    if(root==NULL){
        return root;
    }
    if(root->data < del){
        root->right = delete(root->right,del);
    }
    else if(root->data > del){
        root->left = delete(root->left,del);
    }
    else {
        //for last node or for any one side of sub tree of the node
        if(root->left == NULL){
            node* temp=root->right;
            free(root);
            return temp;
        }
        if(root->right == NULL){
            node* temp = root->left;
            free(root);
            return temp;
        }
        node* min = findMin(root->right);
        root->data = min->data;
        root->right = delete(root->right,min->data);
    }   
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
void main(){
    node* root;
    root = takeinput(root);
    printf("inorder : ");
    inorder(root);
    int del;
    printf("\nEnter the data want to delete : ");
    scanf("%d",&del);
    delete(root,del);
    printf("after deleteing, inorder : ");
    inorder(root);
}

