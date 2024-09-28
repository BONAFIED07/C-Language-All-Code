#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int data);
int dequeue();
void print();
int isEmpty();

int main(){
while(1){
    printf("1. INPUT\n");
    printf("2. DELETE\n");
    printf("3. PRINT\n");
    printf("4. EXIT\n");
    printf("Write The Choice You Want to Apply : ");
    int choice;
    scanf("%d",&choice);

    switch(choice){
        case 1:
            printf("Enter the Element you want to enter in the Queue: ");
            int data;
            scanf("%d",&data);
            enqueue(data);
            printf("Data inserted Successfully!\n");
            break;
        case 2:
            printf("Deleted Element in %d.\n",dequeue());
            break;
        case 3:
            print();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("Invalid Choice");
            break;
    }
}
}

void enqueue(int value){
    struct node *temp;
    temp  = malloc(sizeof(struct node));
    temp->data= value;
    temp->link = NULL;
    if(rear == NULL){
        rear = front = temp;
    }
    else{
        rear->link= temp;
        rear =temp;
    }
}

int dequeue(){
    int data;
    struct node *temp;
    if(isEmpty()){
        printf("Queue Underflowed.\n");
        exit(1);
    }
    else{
        temp=front;
        data= temp->data;
        front = front ->link;
        free(temp);
    }
    return data;
}

void print(){
    if(isEmpty()){
        printf("Queue Underflowed.\n");
        exit(1);
    }
    else{
        struct node *temp;
        temp=front;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->link;
        }
        printf("\n");
    }
}

int isEmpty(){
    if(front==NULL){
        return 1;
    }
    else{
        return 0;
    }
}