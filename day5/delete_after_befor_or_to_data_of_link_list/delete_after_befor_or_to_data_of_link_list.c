#include <stdio.h>
#include<stdlib.h>
//create linked list and delete the data at the after and befor the any data 
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
//function for delete to the data node at the link list
void delete_Data_Node(int d){
    node* temp;
    node* prev;
    temp = start;
    int flag =1;
    //check link list is empty
    if(start == NULL){
        printf("Link list is empty\n");
    }
    if(start->next==NULL&&start->data==d){
        //single node in link list
        start=NULL;
        free(temp);
    }
    else{
        flag =0;
    }
    while(temp->next != NULL||temp->data==d){
        if(temp->data == d){
            flag =1;
            //for first node
            if(temp==start){
                delete_start();
            }
            //for lest node
            else if(temp->next==NULL){
                delete_end();
            }
            else{
                prev->next=temp->next;
                free(temp);
            }
            break;
        }
        else{
            flag = 0;
            prev = temp;
            temp = temp->next;   
        }
    }
    if(flag==0){
        printf("Given data is not in the list.\n");
    }
}
//function for delete after of the data node at the link list
void delete_Data_At_after(int d){
    node* temp;
    node* post;
    temp = start;
    int flag =1;
    //check link list is empty
    if(start == NULL){
        printf("Link list is empty\n");
    }
    while(temp->next != NULL||temp->data==d){
        if(temp->data == d){
            flag =1;
            //for lest node
            if(temp->next==NULL){
                printf("Given data is last node so, we cann't delete after data.\n");
            }
            else{
                post = temp;
                post = post->next;
                temp->next=post->next;
                free(post);
            }
            break;
        }
        else{
            flag = 0;
            temp = temp->next;
        }
    }
    if(flag==0){
        printf("Given data is not in the list.\n");
    }
}
//function for delete befor of the data node at the link list
void delete_Data_At_befor(int d){
    node* temp;
    node* prev;
    node* prevToprev;
    temp = start;
    int flag =1;
    //check link list is empty
    if(start == NULL){
        printf("Link list is empty\n");
    }
    while(temp->next != NULL||temp->data==d){
        if(temp->data == d){
            flag =1;
            //for start node
            if(temp==start){
                printf("Given data is first node so, we cann't delete befor data.\n");
            }
            else{
                if(prev==start){
                    //for second node, befor node is start node then make second node start 
                    start=temp;
                    free(prev);
                }
                else{
                    prevToprev->next = prev->next;
                    free(prev);
                }
            }
            break;
        }
        else{
            flag = 0;
            prevToprev =prev;
            prev=temp;
            temp = temp->next;
        }
    }
    if(flag==0){
        printf("Given data is not in the list.\n");
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
    int d,ad,bd;
    createList();
    display_List();
    //delete_start();
    //display_List();
    //delete_end();
    //display_List();
    /*printf("Enter the data want to delete : ");
    scanf("%d",&d);
    delete_Data_Node(d);
    display_List();
    */
    printf("Enter the data want to delete after data node : ");
    scanf("%d",&ad);
    delete_Data_At_after(ad);
    display_List();
    
    printf("Enter the data want to delete befor data node : ");
    scanf("%d",&bd);
    delete_Data_At_befor(bd);
    display_List();
    return 0;
}

