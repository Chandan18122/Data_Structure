#include <stdio.h>
#include<stdlib.h>
//create tree data find the hight of the tree 
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
int count =0;
void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    if(root->left ==NULL && root->right== NULL){
        count += 1;
    }
    inorder(root->right);
}
//function for find the hight of tree
int hight(node* root){
    if(root == NULL){
        return 0;
    }
    int left = hight(root->left);
    int right= hight(root->right);
    if(left>right){
        return left+1;
    }
    else{
        return right+1;
    }
}
//function for check tree is balinced or not 
void isbalanced(node* root){
    //hight of left subtree
    int lh = hight(root->left);
    //hight of right subtree
    int rh = hight(root->right);
    if(abs(lh-rh)<=1){
        printf("Tree is Balinced.\n");
    }
    else{
        printf("Tree is not Balinced.\n");
    }
}
void main(){
    node* root;
    root = createTree(root);
    printf("inorder : ");
    inorder(root);
    int h = hight(root);
    printf("\nhight of tree : %d\n",h);
    isbalanced(root);
}

