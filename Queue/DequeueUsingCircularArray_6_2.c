#include<stdio.h>

#define N 5
int dequeue[N];
int front=-1, rear=-1;

void enqueuefront(int x){
    if((front==0 && rear==N-1) || (front==rear+1)){
        printf("\nDequeue is full\n");
    }
    else if(front==-1 && rear==-1){
        front=rear=0;
        dequeue[front]=x;
    }
    else if(front==0){
        front=N-1;
        dequeue[front]=x;
    }
    else{
        front--;
        dequeue[front]=x;
    }
}

void enqueuerear(int x){
    if((front==0 && rear==N-1) || (front==rear+1)){
        printf("\nDequeue is full\n");
    }
    else if(front==-1 && rear==-1){
        front=rear=0;
        dequeue[rear]=x;
    }
    else if(rear==N-1){
        rear=0;
        dequeue[rear]=x;
    }
    else{
        rear++;
        dequeue[rear]=x;
    }
}

void display(){
    int i=front;
    if(front==-1 && rear==-1){
        printf("\nDequeue is empty\n");
    }
    else{
        printf("\nDeueue element is ");
        while(i!=rear){
            printf("%d ",dequeue[i]);
            i=(i+1)%N;
        }
        printf("%d",dequeue[rear]);
        printf("\n");
    }
}

void getfront(){
    if(front==-1 && rear==-1){
        printf("\nDequeue is empty\n");
    }
    else{
        printf("\nGet front element is %d\n",dequeue[front]);
    }
}

void getrear(){
    if(front==-1 && rear==-1){
        printf("\nDequeue is empty\n");
    }
    else{
        printf("\nGet rear element is %d\n",dequeue[rear]);
    }
}

void dequeuefront(){
    if(front==-1 && rear==-1){
        printf("\nDequeue is empty\n");
    }
    else if(front==rear){
        printf("\nDequeue front element is %d\n",dequeue[front]);
        front=rear=-1;
    }    
    else if(front==N-1){
        printf("\nDequeue front element is %d\n",dequeue[front]);
        front=0;
    }
    else{
        printf("\nDequeue front element is %d\n",dequeue[front]);
        front++;
    }
}

void dequeuerear(){
    if(front==-1 && rear==-1){
        printf("\nDequeue is empty\n");
    }
    else if(front==rear){
        printf("\nDequeue rear element is %d\n",dequeue[rear]);
        front=rear=-1;
    } 
    else if(rear==0){
        printf("\nDequeue rear element is %d\n",dequeue[rear]);
        rear=N-1;
    }
    else{
        printf("\nDequeue rear element is %d\n",dequeue[rear]);
        rear--;
    }
}

void main(){
    int n,choice;
    do{
        printf("\n**************** MENU ****************\n");
        printf("1.enqueuefront()\n2.enqueuerear()\n3.dequeuefront()\n4.dequeuerear()\n5.getfront()\n6.getrear()\n7.display()\n8.exit\n");
        printf("Enter a choice : ");
        scanf("%d",&choice);
        printf("\n");
        switch(choice){
            case 1:
                printf("Enter a element : ");
                scanf("%d",&n);
                enqueuefront(n);
                break;
            case 2:
                printf("Enter a element : ");
                scanf("%d",&n);
                enqueuerear(n);
                break;
            case 3:
                dequeuefront();
                break;
            case 4:
                dequeuerear();
                break;
            case 5:
                getfront();
                break;
            case 6:
                getrear();
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exit");
                break;
            default:
                printf("Invalid input");
        }
    }
    while(choice!=8);

}