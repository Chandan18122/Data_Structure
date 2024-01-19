#include <stdio.h>
#include<string.h>
//reverse the string using stack
int top = -1;
int size = 50;
char stack[10] = "hello";

int PUSH(int stack[], int data){
    if(top == size- 1){
        printf("Stack overflow.\n");
    }
    top +=1;
    stack[top] = data;
    //printf("%c is add in the stack.\n",stack[top]);
    
}
int POP(int stack[]){
    if(top==-1){
        printf("stack is empty.\n");
    }
    top -=1;
    //printf("%c is removed form stack.\n",stack[top+1]);
    return stack[top+ 1];
}
int main()
{
    
    int a[10];
    printf("string : %s \n",stack);
    for(int i=0;i<strlen(stack);i++){
        PUSH(a,stack[i]);
    }
    int i;
    for( i=0;i<strlen(stack);i++){
        stack[i] = POP(a);
    }
    stack[i] = '\0';
    printf("reverse string : %s",stack);
    return 0;
}

