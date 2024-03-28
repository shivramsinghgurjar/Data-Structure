#include<stdio.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x){
    if(rear==N-1){
        printf("\nOverflow\n");
    }
    else if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }
}

void display(){
    int i;
    if(front==-1 && rear==-1){
        printf("\nQueue is empty\n");
    }
    else{
        printf("\nQueue is : ");
        for(i=0;i<rear+1;i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
void dequeue(){
    if(front==-1 && rear==-1){
        printf("\nUnderflow\n");
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        printf("\nDeleted element is %d\n",queue[front]);
        front++;
    }
}

void peek(){
    if(front==-1 && rear==-1){
        printf("\nQueue is empty\n");
    }
    else{
        printf("\nPeek element is %d\n",queue[front]);
    }
}

void main(){
    enqueue(2);
    enqueue(5);
    enqueue(-1);
    display();
    peek();
    dequeue();
    peek();
    display();
}