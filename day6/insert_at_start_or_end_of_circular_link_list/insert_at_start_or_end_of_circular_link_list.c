#include <stdio.h>
#include<stdlib.h>
//circular link list insert at first and end
typedef struct node{
    int data;
    struct node* next;
}node;
node* start = NULL;
node* last;

struct node* createNode(){
    node* new = malloc(sizeof(node));
    //printf("Enter data for node : ");
    scanf("%d",&new->data);
    new->next = NULL;
    return new;
}
//function to create the circular link list
void create_circular_List(){
    int n;
    printf("Enter the no. want to create list : ");
    scanf("%d",&n);
    //for first node
    node* new;
    printf("Enter data for 1 node : ");
    new = createNode();
    start=new;
    last=new;
    new->next =start;
    //for add more node
    for(int i=1;i<n;i++){
        node* new;
        printf("Enter data for %d node : ",i+1);
        new = createNode();
        last->next = new;
        last=new;
        new->next = start;
    }
}
//function for insert data at the start
void insert_start(){
    node* new ;
    printf("Enter data for node to insert at start : ");
    new = createNode();
    if(start == NULL){
        start=new;
        new->next = start;
        last=new;
    }
    else{
        new->next = start;
        start=new;
        last->next=start;
    }
}
//function for insert date at the end
void insert_End(){
    //create node for insert the data 
    node* new;
    printf("enter data for node to insert at end : ");
    new = createNode();
    if(start==NULL){
        //for new node
        start=new;
        new->next=start;
        last=new;
    }
    else{
        last->next=new;
        new->next=start;
        last=new;
    }
}
//function to display the circular link list
void display_List(){
    //traverse the linked list
    node* ptr;
    ptr = start;
    int i=1;
    if(start == NULL){
        printf("Link list is empty. \n");
    }
    else{
        do{
            //printf("Node %d , data = %d \n",i,ptr->data);
            printf(" --> %d",ptr->data);
            //i++;
            ptr = ptr->next;
        }while(ptr != start);
        printf("\n");
    }
}
int main()
{
    create_circular_List();
    display_List();
    insert_start();
    display_List();
    insert_End();
    display_List();
    return 0;
}

