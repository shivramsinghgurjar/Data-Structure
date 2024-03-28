#include<stdio.h>

#define N 5
int s1[N], s2[N];
int top1=-1, top2=-1;
int count=0;

void push1(int data){
    if(top1==N-1){
        printf("\nOverflow\n");
    }
    else{
        top1++;
        s1[top1] = data;
    }
}

void push2(int data){
    if(top2==N-1){
        printf("\nOverflow\n");
    }
    else{
        top2++;
        s2[top2] = data;
    }
}

int pop1(){
    return s1[top1--];
}

int pop2(){
    return s2[top2--];
}

void enqueue(int x){
    push1(x);
    count++;
}

void dequeue(){
    int i,a,b;
    if(top1==-1 && top2==-1){
        printf("\nUnderflow\n");
    }
    else{
        for(i=0;i<count;i++){
            a=pop1();
            push2(a);
        }
        b=pop2();
        printf("\nDequeue element is %d\n",b);
        count--;
        for(i=0;i<count;i++){
            a=pop2();
            push1(a);
        }
    }
}

void display(){
    int i;
    printf("\nQueue is ");
    for(i=0;i<=top1;i++){
        printf("%d ",s1[i]);
    }
}

void main(){
    int n,choice;
    do{
        printf("\n**************** MENU ****************\n");
        printf("1.enqueue()\n2.display()\n3.dequeue()\n4.exit\n");
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
                printf("Exit");
                break;
            default:
                printf("Invalid input");
        }
    }
    while(choice!=4);

}