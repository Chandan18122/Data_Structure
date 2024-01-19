#include <stdio.h>
#include<stdlib.h>
//create circular link list
typedef struct node{
    int data;
    struct node* next;
}node;
node* start;
node* last;

void create_circular_List(){
    int n;
    printf("Enter the no. want to create list : ");
    scanf("%d",&n);
    //for first node
    node* new = malloc(sizeof(node));
    printf("enter data for 1 node : ");
    scanf("%d",&new->data);
    start=new;
    last=new;
    new->next =start;
    //for add more node
    for(int i=1;i<n;i++){
        node* new = malloc(sizeof(node));
        printf("enter data for %d node : ",i+1);
        scanf("%d",&new->data);
        last->next = new;
        last=new;
        new->next = start;
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
    return 0;
}

