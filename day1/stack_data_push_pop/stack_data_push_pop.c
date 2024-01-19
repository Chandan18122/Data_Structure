#include <stdio.h>
//stack data type insert data and remove data
int top = -1;
int size = 5;

int PEEP(){
    
}
int PUSH(int stack[], int data){
    if(top == size- 1){
        printf("Stack overflow.\n");
    }
    top +=1;
    stack[top] = data;
    printf("%d is add in the stack.\n",stack[top]);
    
}
int POP(int stack[]){
    if(top==-1){
        printf("stack is empty.\n");
    }
    top -=1;
    printf("%d is removed form stack.\n",stack[top+1]);
    return stack[top+ 1];
}
int main()
{
    int s[size];
    PUSH(s,10);
    PUSH(s,20);
    PUSH(s,30);
    PUSH(s,40);
    PUSH(s,50);
    POP(s);
    POP(s);
    PUSH(s,20);
    PUSH(s,50);
    POP(s);
    PUSH(s,60);
    for(int i=0;i<=top;i++){
        printf("Stack data[%d] : %d\n",i,s[i]);
    }
    return 0;
}


