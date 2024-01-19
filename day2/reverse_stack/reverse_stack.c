#include <stdio.h>
//stack data type insert data and remove data
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
void insert_at_bottom(int stack[],int data){
    if(top==-1){
        PUSH(stack,data);
        return;
    }
    int x = POP(stack);
    insert_at_bottom(stack,data);
    PUSH(stack,x);
}
void reverse_stack(int stack[]){
    if(top==0){
        return;
    }
    int x = POP(stack);
    reverse_stack(stack);
    insert_at_bottom(stack,x);
}
int main()
{
    int a[size];
    PUSH(a,10);
    PUSH(a,20);
    PUSH(a,30);
    PUSH(a,40);
    PUSH(a,50);
    reverse_stack(a);
    for(int i=0;i<top+1;i++){
        printf("Stack data[%d] : %d\n",i,a[i]);
    }
    return 0;
}

