#include <stdio.h>
#include<stdlib.h>
//circular link list delet at first and end
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
//function for delet the first node of the circular link list
void delete_start(){
    node* temp;
    temp = start;
    //check link list is empty
    if(start == NULL){
        printf("Link list is empty");
    }
    else if(start->next == start){
        //for single node link list
        start = NULL;
        last = NULL;
        free(temp);
    }
    else {
        //for more node
        start = start->next;
        free(temp);
        last->next = start;
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
    else if(start->next == start){
        //for single node link list
        start = NULL;
        free(temp);
    }
    else {
        //for more node
        while(temp->next != start){
            prev=temp;
            temp=temp->next;
        }
        prev->next =NULL;
        free(temp);
        prev->next = start;
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
    delete_start();
    display_List();
    delete_end();
    display_List();
    return 0;
}

