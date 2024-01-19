#include <stdio.h>
//Circular queue

int f=-1;
int r=-1;
int n=5;
int q[5];
int enqueue(int data){
    if((f==0&& r==n-1)|| r==f-1||f==r+1){
        printf("Queue is overflow.");
        //return;
    }
    else{
        //increment f is first element
        if(f==-1){
            f=0;
        }
        //r=(r+ 1)%n;//Circular case
        if(r==n-1){
            r=0;
        }
        else{
            r++;
        }
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
            //f=(f+1)%n //for Circular rotation
            if(f==n-1){
                f=0;
            }
            else{
                f++;
            }
        }
        printf("\nData = %d is deleted form queue f = %d, r= %d.",data,f,r);
    }
}
void display(){
    //print the data having Circular queue
    if(f<=r){
        printf("\nCircular Queue data : ");
        for(int i=f;i<=r;i++){
            printf("%d ",q[i]);
        }
    }
    else{
        printf("\nCircular Queue data : ");
        for(int i=f;i<n;i++){
            printf("%d ",q[i]);
        }
        for(int i=0;i<=r;i++){
            printf("%d ",q[i]);
        }
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
    //enqueue(60);
    display();
    dqueue();
    display();
    enqueue(60);
    display();
    dqueue();
    dqueue();
    //dqueue();
    dqueue();
    //dqueue();
    display();
    return 0;
}

