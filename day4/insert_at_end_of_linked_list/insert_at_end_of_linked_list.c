#include <stdio.h>
#include<stdlib.h>
//create linked list and insert the data at the end 
typedef struct node{
    int data;
    struct node* next;
}node;
node* start;

void createList(){
    int n;
    printf("Enter the no. want to create list : ");
    scanf("%d",&n);
    node* ptr;
    //for first node
    node* new = malloc(sizeof(node));
    printf("enter data for 1 node : ");
    scanf("%d",&new->data);
    new->next = NULL;
    start=new;
    ptr=new;
    //for add more node
    for(int i=1;i<n;i++){
        node* new = malloc(sizeof(node));
        printf("enter data for %d node : ",i+1);
        scanf("%d",&new->data);
        new->next = NULL;
        ptr->next = new;
        ptr=new;
    }
}
void insert_End(){
    //create node for insert the data 
    node* new = malloc(sizeof(node));
    printf("enter data for node : ");
    scanf("%d",&new->data);
    new->next = NULL;
    //pointer for point the start node 
    node* temp;
    temp =start;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new;
}
void display_List(){
    //traverse the linked list
    node* ptr;
    ptr = start;
    int i=1;
    while(ptr != NULL){
        printf("Node %d , data = %d \n",i,ptr->data);
        i++;
        ptr = ptr->next;
    }
}
int main()
{
    createList();
    display_List();
    insert_End();
    
    display_List();
    return 0;
}

