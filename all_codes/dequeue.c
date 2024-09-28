#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
    struct node *prev;
};

struct node *head;   //for printing forward
struct node *current;
struct node *temp;   //for printing backward
int a,b,c;

void pop();
void popback();

int main(){
    int num;
    printf("Write the Num of Links You Want : ");
    scanf("%d",&num);
    int i=1;

    while(1){
        if(i>num){
            break;
        }
            else if(i==1){
                head = malloc(sizeof(struct node));
                printf("Write the Value For Node 1 : ");
                scanf("%d",&a);
                head->data=a;
                head->link= NULL;
                head->prev= NULL;
            }
            else if(i==2){
                current = malloc(sizeof(struct node));
                printf("Write the Value For Node %d : ",i);
                scanf("%d",&b);
                current->data = b;
                current->link= NULL;
                current->prev= head;
                head->link = current;
            }
            else{
                temp = malloc(sizeof(struct node));
                printf("Write The Value for Node %d : ",i);
                scanf("%d",&c);
                temp->data=c;
                temp->link=NULL;
                temp->prev=current;
                current->link=temp;
                current=current->link;
            }
            i++;

        }
        while(1){
        printf("1. POP\n");
        printf("2. POP BACK\n");
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1:
                pop();
                break;
            case 2:
                popback();
                break;
        }
        }
}

void pop(){
    if(temp==NULL){
        printf("\nEMPTY!!\n");
    }
    else{
        printf("\n%d\n",temp->data);
        temp=temp->link;
    }
}

void popback(){
    if(head==NULL){
        printf("\nEMPTY!!\n");
    }
    else{
        printf("\n%d\n",head->data);
        head=head->link;
    }
}