#include <stdio.h>
#include<stdlib.h>
//create linked list and insert the data at the after and befor the any data 
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
//function for insert data at the start
void insert_start(){
    node* new = malloc(sizeof(node));
    printf("Enter data for node to insert at start : ");
    scanf("%d",&new->data);
    if(start == NULL){
        new->next = NULL;
        start=new;
        lest=new;
    }
    else{
        new->next = start;
        start=new;
    }
}
//function for insert date at the end
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
//function for insert data at after ot the any data 
void insert_At_After(int a){
    node* temp;
    temp = start;
    if(start == NULL){
        printf("Ther is not any type of list data.");
    }
    else{
        int flag;
        while(temp->next != NULL||temp->data==a){
            flag =0;
            if(temp == lest){
                insert_End();
                break;
            }
            if(temp->data == a){
                node* new = malloc(sizeof(node));
                printf("Enter data for node to insert after %d : ",a);
                scanf("%d",&new->data);
                new->next=temp->next;
                temp->next=new;
                break;
            }
            else{
                //the data is not match in the list 
                temp = temp->next;
                flag=1;
            }
        }
        if(flag == 1){
            printf("Given data is not in the list.");
        }
    }
}
//function for insert data at befor at the any data 
void insert_At_Befor(int b){
    node* temp;
    node* prev;
    temp = start;
    if(start == NULL){
        printf("Ther is not any type of list data.");
    }
    else{
        int flag;
        while(temp->next != NULL){
            flag =0;
            if(temp == start){
                insert_start();
                break;
            }
            if(temp->data == b){
                node* new = malloc(sizeof(node));
                printf("Enter data for node to insert befor %d : ",b);
                scanf("%d",&new->data);
                new->next=prev->next;
                prev->next=new;
                break;
            }
            else{
                //the data is not match in the list 
                prev = temp;
                temp = temp->next;
                flag=1;
            }
        }
        if(flag == 1){
            printf("Given data is not in the list.");
        }
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
}
int main()
{
    int a,b;
    createList();
    display_List();
    //insert_End();
    //display_List();
    //insert_start();
    //display_List();
    printf("\nEnter those data where to insert at after : ");
    scanf("%d",&a);
    insert_At_After(a);
    display_List();
    printf("\nEnter those data where to insert at befor : ");
    scanf("%d",&b);
    insert_At_Befor(b);
    display_List();
    return 0;
}


