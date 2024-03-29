#include<stdio.h>

#define N 5
int stack[N];
int top=-1;

void push(){
    int x;
    printf("Enter a element : ");
    scanf("%d",&x);
    if(x==N-1){
        printf("\nOverflow\n");
    }
    else{
        top++;
        stack[top]=x;
    }
}

void pop(){
    if(top==-1){
        printf("\nUnderflow\n");
    }
    else{
        printf("\nDeleted element is : %d\n",stack[top]);
        top--;
    }
}

void peek(){
    if(top==-1){
        printf("\nStack is empty\n");
    }
    else{
        printf("\nPeek element is : %d\n",stack[top]);
    }
}

void display(){
    int i;
    if(top==-1){
        printf("\nStack is empty\n");
    }
    else{
        printf("\nStack is ");
        for(i=top;i>=0;i--){
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
}

void main(){
    int choice;
    do{
        printf("\n************** MENU **************\n");
        printf("\n1.push()\n2.pop()\n3.peek()\n4.display()\n5.exit\n");
        printf("Enter a choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exit");
                break;
            default:
                printf("Invalid Choice");
        }
    }
    while(choice!=5);
}