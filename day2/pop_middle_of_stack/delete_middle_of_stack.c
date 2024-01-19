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
void delete_middle_element(int stack[]){
    if(top== 3){
        POP(stack);
        return;
    }
    int x = POP(stack);
    delete_middle_element(stack);
    PUSH(stack,x);
}
int main()
{
    int a[size];
    PUSH(a,10);
    PUSH(a,20);
    PUSH(a,30);
    PUSH(a,40);
    PUSH(a,50);
    PUSH(a,60);
    PUSH(a,70);
    delete_middle_element(a);
    for(int i=0;i<top+1;i++){
        printf("Stack data[%d] : %d\n",i,a[i]);
    }
    return 0;
}
