#include <stdio.h>
#include<stdlib.h>
//create link list and insert the data at the after and befor the any data 
typedef struct node{
    int data;
    struct node* next;
}node;
node* start;
node* lest;
//function for create the list
void createList(){
    int n;
    printf("Enter the no. want to create list : ");
    scanf("%d",&n);
    //for first node
    node* new = malloc(sizeof(node));
    printf("enter data for 1 node : ");
    scanf("%d",&new->data);
    new->next = NULL;
    start=new;
    lest=new;
    //for add more node
    for(int i=1;i<n;i++){
        node* new = malloc(sizeof(node));
        printf("enter data for %d node : ",i+1);
        scanf("%d",&new->data);
        new->next = NULL;
        lest->next = new;
        lest=new;
    }
}
//function for delet the first node of the link list
void delete_start(){
    node* temp;
    //check link list is empty
    if(start == NULL){
        printf("Link list is empty");
    }
    else if(start->next == NULL){
        //for single node link list
        temp = start;
        start = NULL;
        free(temp);
    }
    else {
        //for more node
        temp = start;
        start = start->next;
        free(temp);
    }
}
//function for delete the lest node of the link list
void delete_end(){
    node* temp;
    node* prev;
    temp = start;
    //check link list is empty
    if(start == NULL){
        printf("Link list is empty");
    }
    else if(start->next == NULL){
        //for single node link list
        start = NULL;
        free(temp);
    }
    else {
        //for more node
        while(temp->next != NULL){
            prev=temp;
            temp=temp->next;
        }
        prev->next =NULL;
        free(temp);
    }
}
//function for display the linked list data
void display_List(){
    //traverse the linked list
    node* ptr;
    ptr = start;
    int i=1;
    while(ptr != NULL){
        printf("-->%d",ptr->data);
        //printf("Node %d , data = %d \n",i,ptr->data);
        i++;
        ptr = ptr->next;
    }
    printf("\n");
}
int main()
{
    int a,b;
    createList();
    display_List();
    delete_start();
    display_List();
    delete_end();
    display_List();
    return 0;
}

