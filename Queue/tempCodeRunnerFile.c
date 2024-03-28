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