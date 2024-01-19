#include <stdio.h>
#include<stdlib.h>
//linked list 
typedef struct node{
    int data;
    struct node* next;
}node;
node* start;
int main()
{
    node* ptr;
    node* n1 = malloc(sizeof(node));
    node* n2 = malloc(sizeof(node));
    node* n3 = malloc(sizeof(node));
    
    n1->data= 10;
    n1->next= n2;
    start =n1;
    n2->data= 20;
    n2->next= n3;
    n3->data= 30;
    n3->next= NULL;
    //traverse the linked list
    ptr = start;
    int i=1;
    while(ptr != NULL){
        printf("Node %d , data = %d \n",i,ptr->data);
        i++;
        
        ptr = ptr->next;
    }
    
    return 0;
}

