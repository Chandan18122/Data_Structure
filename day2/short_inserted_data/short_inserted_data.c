#include <stdio.h>
//insert shorted elements
int top = -1;
int size = 50;

int PUSH(int stack[], int data){
    if(top == size- 1){
        printf("Stack overflow.\n");
    }
    top +=1;
    stack[top] = data;
    //printf("%d is add in the stack.\n",stack[top]);
    
}
int POP(int stack[]){
    if(top==-1){
        printf("stack is empty.\n");
    }
    top -=1;
    //printf("%d is removed form stack.\n",stack[top+1]);
    return stack[top+ 1];
}
void short_insert(int stack[],int data){
    if(top == -1){
        PUSH(stack,data);
        return;
    }
    if(stack[top]>data){
        int x = POP(stack);
        short_insert(stack, data);
        
        PUSH(stack,x);
    }
    else{
        PUSH(stack, data);
        return;
    }
}

int main()
{
    int a[size];
    //PUSH(a,30);
    short_insert(a,30);
    short_insert(a,10);
    short_insert(a,50);
    short_insert(a,40);
    short_insert(a,20);
    for(int i=0;i<top+1;i++){
        printf("Stack data[%d] : %d\n",i,a[i]);
    }
    return 0;
}

