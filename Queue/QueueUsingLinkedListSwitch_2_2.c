#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *front = 0;
struct node *rear = 0;

void enqueue(int x){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next=0;

    if(front==0 && rear==0){
        front=rear=newnode;
    } 
    else{
        rear->next=newnode;
        rear=newnode;
    }
}

void display(){
    struct node *temp;
    if(front==0 && rear==0){
        printf("\nQueue is empty\n");
    }
    else{
        temp=front;
        printf("\nQueue is ");
        while(temp!=0){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
void dequeue(){
    struct node *temp;
    temp = front;
    if(front==0 && rear==0){
        printf("\nQueue is empty\n");
    }
    else{
        printf("\nDeleted element is %d\n",front->data);
        front=front->next;
        free(temp);
    }
}

void peek(){
    if(front==0 && rear==0){
        printf("\nQueue is empty\n");
    }
    else{
        printf("\nPeek element is %d\n",front->data);
    }
}

void main(){
    int n,choice;
    do{
        printf("\n***************** MENU *****************\n");
        printf("1.enqueue()\n2.display()\n3.dequeue()\n4.peek()\n5.exit\n");
        printf("Enter a choice : ");
        scanf("%d",&choice);
        printf("\n");
        switch(choice){
            case 1:
                printf("Enter a element : ");
                scanf("%d",&n);
                enqueue(n);
                break;
            case 2:
                display();
                break;
            case 3:
                dequeue();
                break;
            case 4:
                peek();
                break;
            case 5:
                printf("Exit");
                break;
            default:
                printf("Invalid input");    
        }
    }
    while(choice!=5);
}