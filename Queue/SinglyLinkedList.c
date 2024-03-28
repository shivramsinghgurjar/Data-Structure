#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *Root = NULL;
void append();
void display();
void addbegin();
void addlast();
int length();
void addbefore();
void addafter();
void deletefirst();
void deletelast();
void deletebefore();
void deleteafter();
void search();
void reverse();
void sort();

void main()
{

    int i, choice, n;
    do
    {
        printf("\n------------------list-------------------\n");
        printf("0.exit\n1.append\n2.display.\n3.addbegin\n4.addlast\n5.addbefore\n6.addafter\n7.deletefirst\n8.deletelast\n9.deletebefore\n10.deleteafter\n11.search\n12.reverse\n13.sort\n");
        printf("what u want to do.");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 0:
            printf("Exit");
            break;
        case 1:
            printf("Enter the number of node:");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                append();
            }
            break;
        case 2:
            display();
            break;
        case 3:
            addbegin();
            break;
        case 4:
            addlast();
            break;
        case 5:
            addbefore();
            break;
        case 6:
            addafter();
            break;
        case 7:
            deletefirst();
            break;
        case 8:
            deletelast();
            break;
        case 9:
            deletebefore();
            break;
        case 10:
            deleteafter();
            break;
        case 11:
            search();
            break;
        case 12:reverse();
            break;
        case 13:sort();
            break;
        default:
            printf("Invalid Input.\n");
        }
    } while (choice != 0);
}

void append()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node)); 
    printf("Enter the info part of node:");
    scanf("%d", &temp->info);
    temp->next = NULL;
    if (Root == NULL)
    {
        Root = temp;
    }
    else
    {
        struct node *p = Root;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

void display()
{
    if (Root == NULL)
    {
        printf("List Not Found");
    }
    else
    {
        struct node *p = Root;
        while (p != NULL)
        {
            printf("%d-->", p->info);
            p = p->next;
        }
    }
}
void addbegin()
{
    if (Root == NULL)
    {
        printf("List not found");
    }
    else
    {
        struct node *new1;
        new1 = (struct node *)malloc(sizeof(struct node));
        printf("Enter the info you want to add in begin:");
        scanf("%d", &new1->info);
        new1->next = Root;
        Root = new1;
        display();
    }
}

void addlast()
{
    if (Root == NULL)
    {
        printf("List Not Found.");
    }
    else
    {
        struct node *new1;
        new1 = (struct node *)malloc(sizeof(struct node));
        printf("Enter element you want to add in last:");
        scanf("%d", &new1->info);
        new1->next = NULL;
        struct node *p = Root;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = new1;
        display();
    }
}

int length()
{
    int count = 0;
    struct node *p = Root;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

void addbefore()
{
    if (Root == NULL)
    {
        printf("List not Found");
    }
    else
    {
        int loc, len;
        len = length();
        printf("Enter the position you wants to insert before:");
        scanf("%d", &loc);
        if (loc > len)
        {
            printf("Insertion is not possible.");
        }
        else
        {
            int i = 1;
            struct node *p = Root;
            while (i < loc - 1)
            {
                p = p->next;
                i++;
            }
            struct node *new1;
            new1 = (struct node *)malloc(sizeof(struct node));
            printf("Enter the element you want to insert: ");
            scanf("%d", &new1->info);
            new1->next = p->next;
            p->next = new1;
            display();
        }
    }
}

void addafter()
{
    if (Root == NULL)
    {
        printf("List not Found");
    }
    else
    {
        int loc, len;
        len = length();
        printf("Enter the postion you want to insert:");
        scanf("%d", &loc);
        if (loc > len)
        {
            printf("Insertion not possible.");
        }
        else
        {
            int i = 1;
            struct node *p = Root;
            while (i < loc)
            {
                p = p->next;
                i++;
            }
            struct node *new1;
            new1 = (struct node *)malloc(sizeof(struct node));
            printf("Enter the element you want to add after:");
            scanf("%d", &new1->info);
            new1->next = p->next;
            p->next = new1;

            display();
        }
    }
}
void deletefirst()
{
    if (Root == NULL)
    {
        printf("List not found.");
    }
    else
    {
        struct node *temp = Root;
        Root = temp->next;
        printf("Deleted element:%d\n", temp->info);
        free(temp);
        display();
    }
}

void deletelast()
{
    if (Root == NULL)
    {
        printf("List not Found.");
    }
    else
    {
        struct node *p = Root;
        struct node *prev;
        while (p->next != NULL)
        {
            prev = p;
            p = p->next;
        }
        prev->next = NULL;
        printf("Deleted element:%d\n", p->info);
        free(p);
        display();
    }
}

void deletebefore()
{
    if (Root == NULL)
    {
        printf("List Not Found");
    }
    else
    {
        int i = 1, j = 1, loc, len;
        len = length();
        printf("Enter the position you want to delete before:");
        scanf("%d", &loc);
        while (loc > len)
        {
            printf("Invalid Input.");
        }
        struct node *p = Root;
        struct node *prev = Root;
        while (i < loc - 1)
        {
            p = p->next;
            i++;
        }
        while (j < loc - 2)
        {
            prev = prev->next;
            j++;
        }
        prev->next = p->next;
        free(p);
        display();
    }
}

void deleteafter()
{
    if (Root == NULL)
    {
        printf("List Not Found");
    }
    else
    {
        int i = 1, j = 1, loc, len;
        len = length();
        printf("Enter the position you want to delete after:");
        scanf("%d", &loc);
        while (loc > len)
        {
            printf("Invalid Input.");
        }
        struct node *p = Root;
        struct node *prev = Root;
        while (i < loc)
        {
            p = p->next;
            i++;
        }
        while (j < loc + 1)
        {
            prev = prev->next;
            j++;
        }
        p->next = prev->next;
        free(prev);
        display();
    }
}
void search()
{
    if (Root == NULL)
    {
        printf("List Not found.");
    }
    else
    {
        int s, i = 0, x = 1, y = 1;
        printf("\nEnter the element you want to search:");
        scanf("%d", &s);
        struct node *p = Root;
        while (p != NULL)
        {
            if (p->info == s)
            {
                i = 1;
                y = x;
            }
            x++;
            p = p->next;
        }
        if (i == 1)
        {
            printf("element is found at index:%d", y);
        }
        else
        {
            printf("element not found.");
        }
    }
}
void reverse(){
    struct node*p=Root,*q=Root;
    int len=length();
    int i=0,j=len,temp;
    while(i<j){
        int k=1;
        while(k<j){
            q=q->next;
            k++;
        }
        temp=p->info;
        p->info=q->info;
        q->info=temp;
        i++,j--,p=p->next,q=Root;
    }
    display();
}
void sort(){
    struct node*p=Root;
    struct node*q;
    int temp;
    while(p!=NULL){
        q=p->next;
        while(q!=NULL){
            if(q->info<p->info){
                temp=p->info;
                p->info=q->info;
                q->info=temp;
            }
        q=q->next;
        }
        p=p->next;
    }
    display();

}