#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
    struct node *prev;
};
struct node *head;
struct node *current;
struct node *temp;
int a,b,c;

void print(){
    if(head==NULL){
        print("No element.\n");
    }
    else{
        struct node *traverse=head;
        printf("Ordered Element : ");
        while(traverse!=NULL){
            printf("%d ",traverse->data);
            traverse=traverse->link;
        }
        printf("\n");
    }
}

void printrev(){
    struct node *back= temp;
    printf("Reverse Elemet : ");
    while(back!=NULL){
        printf("%d ",back->data);
        back=back->prev;
    }
    printf("\n");
}


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
        temp->link=head;
        head->prev=temp;

    print();
    printrev();

}


