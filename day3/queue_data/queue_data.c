#include <stdio.h>
//queue data type

int f=-1;
int r=-1;
int n=5;
int q[5];
int enqueue(int data){
    if(r==n-1){
        printf("Queue is overflow.");
        //return;
    }
    else{
        //increment f is first element
        if(f==-1){
            f=0;
        }
        r++;
        q[r] = data;
        printf("\nData = %d is inserted in queue f = %d, r= %d.",data,f,r);
    }
}
int dqueue(){
    if(f==-1){
        printf("Queue is Underflow.");
        //return;
    }
    else{
        int data = q[f];
        //delete f is first element
        if(f==r){
            r=-1;
            f=-1;
        }
        else{
            f++;
        }
        printf("\nData = %d is deleted form queue f = %d, r= %d.",data,f,r);
    }
}
void display(){
    //print the data having queue
    printf("\nQueue data : ");
    for(int i=f;i<=r;i++){
        printf("%d ",q[i]);
    }
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    enqueue(40);
    enqueue(50);
    display();
    enqueue(60);
    dqueue();
    enqueue(60);
    display();
    dqueue();
    dqueue();
    //dqueue();
    //dqueue();
    //dqueue();
    display();
    
    return 0;
}
