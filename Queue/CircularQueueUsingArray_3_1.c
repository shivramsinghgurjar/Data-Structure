#include<stdio.h>

#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x){
    if((rear+1)%N == front){
        printf("\nQueue is full\n");
    }
    else if(front==-1 && rear==-1){
        front = rear = 0;
        queue[rear] = x;
    }
    else{
        rear = (rear+1)%N;
        queue[rear] = x;
    }
}

void dequeue(){
    if(front==-1 && rear==-1){
        printf("\nQueue is empty\n");
    }
    else if(front==rear){
        printf("\nDequeue element is %d\n",queue[front]);
        front=rear=-1;
    }
    else{
        printf("\nDequeue element is %d\n",queue[front]);
        front = (front+1)%N;
    }
}

void display(){
    int i=front;
    if(front==-1 && rear==-1){
        printf("\nQueue is empty\n");
    }
    else{
        printf("\nQueue is ");
        while (i!=rear){
            printf("%d ",queue[i]);
            i=(i+1)%N;   
        }
        printf("%d",queue[rear]);  
        printf("\n");
    }
}

void main(){
    enqueue(2);
    enqueue(-1);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    display();
    dequeue();
    dequeue();
    enqueue(0);
    enqueue(10);
    enqueue(11);
    display();
}