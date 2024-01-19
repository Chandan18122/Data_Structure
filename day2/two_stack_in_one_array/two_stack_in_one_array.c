#include <stdio.h>
//perform two stack operation in one array
int top1 = -1;
int size = 10;
int top2 = 10;

int PUSH1(int stack[], int data){
    if(top1 == top2 - 1){
        printf("Stack overflow.\n");
    }
    if(top2-top1>1){
        top1 +=1;
        stack[top1] = data;
        //printf("%d is add in the stack.\n",stack[top]);
    }
}
int PUSH2(int stack[], int data){
    if(top2 == top1- 1){
        printf("Stack overflow.\n");
    }
    if(top2-top1>1){
        top2 -=1;
        stack[top2] = data;
        //printf("%d is add in the stack.\n",stack[top]);
    }
}
int POP1(int stack[]){
    if(top1==-1){
        printf("stack is empty.\n");
    }
    top1 -=1;
    //printf("%d is removed form stack.\n",stack[top+1]);
    return stack[top1+ 1];
}
int POP2(int stack[]){
    if(top2==size){
        printf("stack is empty.\n");
    }
    top2 +=1;
    //printf("%d is removed form stack.\n",stack[top+1]);
    return stack[top2- 1];
}
int main()
{
    int a[size];
    PUSH1(a,10);
    PUSH1(a,20);
    PUSH1(a,30);
    PUSH1(a,40);
    PUSH1(a,50);
    PUSH1(a,60);
    POP1(a);
    PUSH2(a,70);
    PUSH2(a,80);
    PUSH2(a,90);
    PUSH2(a,100);
    POP2(a);
    POP1(a);
    POP2(a);
    PUSH2(a,50);
    PUSH1(a,20);
    POP2(a);
    for(int i=0;i<size;i++){
        printf("%d  ",a[i]);
    }
    printf("\n");
    for(int i=0;i<=top1;i++){
        printf("Stack 1 data[%d] : %d\n",i,a[i]);
    }
    for(int i=size-1;i>=top2;i--){
        printf("Stack 2 data[%d] : %d\n",i,a[i]);
    }
    return 0;
}

