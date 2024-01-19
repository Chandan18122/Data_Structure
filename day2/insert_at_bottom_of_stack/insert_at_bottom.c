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
int main()
{
    int a[size];
    int data = 100;
    PUSH(a,10);
    PUSH(a,20);
    PUSH(a,30);
    insert_at_bottom(a, data);
    for(int i=0;i<top+1;i++){
        printf("Stack data[%d] : %d\n",i,a[i]);
    }
    return 0;
}
