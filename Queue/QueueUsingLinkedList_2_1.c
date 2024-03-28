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
    enqueue(5);
    enqueue(0);
    enqueue(-2);
    display();
    dequeue();
    peek();
}