#include <stdio.h>
//short stack elements
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
void short_stack(int stack[]){
    if(top == -1){
        return;
    }
    int x = POP(stack);
    short_stack(stack);
    short_insert(stack,x);
}
int main()
{
    int a[size];
    PUSH(a,100);
    PUSH(a,30);
    PUSH(a,10);
    PUSH(a,50);
    PUSH(a,40);
    PUSH(a,20);
    PUSH(a,60);
    short_stack(a);
    for(int i=0;i<top+1;i++){
        printf("Stack data[%d] : %d\n",i,a[i]);
    }
    return 0;
}

