#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    int priority;
    struct node *link;
};

struct node *head;
struct node *one;
struct node *two ;
struct node *current;

void print(){
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->link;
    }
}

void prio_rity(){
    if(head->priority > one->priority){
        current=head;
        if(one->priority > two->priority){
        current->link=one;
        one->link=two;
        two->link=NULL;
        }
        else{
            current->link=two;
            two->link=one;
            one->link=NULL;
        }
    }
    if(one->priority > head->priority){
        current=one;
        if(head->priority > two->priority){
        current->link=head;
        head->link=two;
        two->link=NULL;
        }
        else{
            current->link=two;
            two->link=head;
            head->link=NULL;
        }
    }
    if(two->priority > head->priority){
        current=two;
        if(head->priority > one->priority){
        current->link=head;
        head->link=one;
        one->link=NULL;
        }
        else{
            current->link=one;
            one->link=head;
            head->link=NULL;
        }
    }
}

int main(){
head= malloc(sizeof(struct node));
two= malloc(sizeof(struct node));
one= malloc(sizeof(struct node));

    head->link = one;
    one->link=two;
    two->link=NULL;

    int data,priority;
    int num = 3;
    int i=1;
    struct node *temp= head;
    while(num--){
        printf("Write Data and preference %d element : ",i);
        scanf("%d %d",&data,&priority);
        temp->data = data;
        temp->priority=priority;
        temp=temp->link;
        i++;
    }
    prio_rity();
    print();
    
}