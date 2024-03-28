#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *front=0;
struct node *rear=0;

void enqueue(int x){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = 0;

    if(rear==0){
        front=rear=newnode;
        rear->next=front;
    }
    else{
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
    }
}

void dequeue(){
    struct node *temp;
    temp = front;
    if (front==0 && rear==0){
        printf("\nQueue is empty\n");
    }
    else if(front==rear){
        printf("\nDequeue element is %d\n",front->data);
        front=rear=0;
        free(temp);
    }
    else{
        printf("\nDequeue element is %d\n",front->data);
        front=front->next;
        rear->next=front;
        free(temp);
    }
}

void peek(){
    if(front==0 && rear==0){
        printf("\nQueue is empty\n");
    }
    else{
        printf("\nPeek element id %d\n",front->data);
    }
}

void display(){
    struct node *temp;
    temp = front;
    if(front==0 && rear==0){
        printf("\nQueue is empty\n");
    }
    else{
        printf("\nCircular Queue element is ");
        while(temp->next!=front){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
        printf("\n");
    }
}

void main(){
    enqueue(2);
    enqueue(-1);
    enqueue(5);
    display();
    dequeue();
    peek();
}