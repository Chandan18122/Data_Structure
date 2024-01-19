#include <stdio.h>
#include<stdlib.h>
//create linked list and insert the data at the startand end
typedef struct node{
    int data;
    struct node* next;
}node;
node* start;
node* lest;
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
void insert_start(){
    //create node for insert the data 
    node* new = malloc(sizeof(node));
    printf("Enter data for node to insert at start : ");
    scanf("%d",&new->data);
    if(start == NULL){
        //for new node
        new->next = NULL;
        start=new;
        lest=new;
    }
    else{
        new->next = start;
        start=new;
    }
}
void insert_End(){
    //create node for insert the data 
    node* new = malloc(sizeof(node));
    printf("enter data for node to insert at end : ");
    scanf("%d",&new->data);
    new->next = NULL;
    if(start==NULL){
        //for new node
        start=new;
        lest=new;
    }
    else{
        lest->next=new;
        lest=new;
    }
}
void display_List(){
    //traverse the linked list
    node* ptr;
    ptr = start;
    int i=1;
    while(ptr != NULL){
        //printf("-->%d",ptr->data);
        printf("Node %d , data = %d \n",i,ptr->data);
        i++;
        ptr = ptr->next;
    }
}
int main()
{
    //createList();
    display_List();
    insert_End();
    display_List();
    insert_start();
    display_List();
    return 0;
}

