#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *top=0;

void push(int x){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next=top;
    top=newnode;
}

void display(){
    struct node *temp;
    temp=top;
    if(top==0){
        printf("\nStack is empty\n");
    }
    else{
        printf("\nStack is ");
        while(temp!=0){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

void peek(){
    if(top==0){
        printf("\nStack is empty\n");
    }
    else{
        printf("Peek element is : %d",top->data);
    }
}

void pop(){
    struct node *temp;
    temp=top;
    if(top==0){
        printf("\nStack is empty\n");
    }
    else{
        printf("\nDeleted element is : %d",top->data);
        top=top->next;
        free(temp);
    }
}

void main(){
    int choice,n;
    do{
        printf("\n************** MENU **************\n");
        printf("\n1.push()\n2.pop()\n3.peek()\n4.display()\n5.exit\n");
        printf("Enter a choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter a element : ");
                scanf("%d",&n);
                push(n);
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