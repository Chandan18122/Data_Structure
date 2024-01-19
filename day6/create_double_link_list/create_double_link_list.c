#include <stdio.h>
#include<stdlib.h>
//create double link list
typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node;
node* start;
node* last;

struct node* createNode(){
    node* new = malloc(sizeof(node));
    scanf("%d",&new->data);
    new->next=NULL;
    new->prev=NULL;
    return new;
}
void create_double_List(){
    int n;
    printf("Enter the no. want to create list : ");
    scanf("%d",&n);
    //for first node
    node* new;
    printf("enter data for 1 node : ");
    new = createNode();
    start=new;
    last = new;
    //for add more node
    for(int i=1;i<n;i++){
        node* new;
        printf("enter data for %d node : ",i+1);
        new = createNode();
        last->next = new;
        new->prev = last;
        last=new;
    }
}
void display_List(){
    //traverse the linked list
    node* ptr;
    ptr = start;
    int i=1;
    if(start == NULL){
        printf("Link list is empty. ");
    }
    else{
        printf("left to right\n");
        while(ptr != NULL){
            //printf("Node %d , data = %d \n",i,ptr->data);
            printf("--> %d",ptr->data);
            //i++;
            ptr = ptr->next;
        }
        printf("\nright to left\n");
        ptr = last;
        while(ptr != NULL){
            printf("--> %d ",ptr->data);
            ptr = ptr->prev;
        }
        printf("\n");
    }
}
int main()
{
    create_double_List();

    display_List();
    return 0;
}

