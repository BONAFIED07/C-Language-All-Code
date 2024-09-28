#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *top;
struct node *top1;
struct node *temp;

void push(int ele)
{
    if (top == NULL)
    {
        top = malloc(sizeof(struct node));
        top->data = ele;
        top->link = NULL;
    }
    else
    {
        temp = malloc(sizeof(struct node));
        temp->data = ele;
        temp->link = top;
        top = temp;
    }
    printf("\nNode Is Inserted!!\n");
}

void pop()
{
    if (top == NULL)
    {
        printf("\nUNDERFLOW\n");
    }
    else
    {
        printf("\n%d\n", top->data);
        top = top->link;
    }
}

void print()
{
    top1 = top;

    if (top1 == NULL)
    {
        printf("\nNOTHING TO PRINT\n");
    }
    else
    {
        while (top1 != NULL)
        {
            printf("%d ", top1->data);
            top1 = top1->link;
        }
    }
}

int main()
{
    printf("\nWELCOME TO WORLD OF STACKS\n");

    while (1)
    {

    printf("\n1. PUSH\n2. POP\n3. PRINT\n4. Break\n");
        printf("\nWrite Your Choice : ");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Your Number : ");
            int a;
            scanf("%d", &a);
            push(a);
            break;

        case 2:
            pop();
            break;

        case 3:
            print();
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Wrong Choice\n");
        }
    }
}