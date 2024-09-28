#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void count_of_nodes(struct node *head){
    if(head==NULL){
    printf("Empty!!");
    return;
    }
    
    struct node *ptr=head;
    int count=0;
    while (ptr!=NULL)
    {
        count++;
        ptr=ptr->link;
    }
    printf("Total Number Of Nodes : %d\n",count);
}

void print_nodes(struct node *head)
{
    if(head==NULL){
    printf("Empty!!");
    return;
    }
    struct node *ptr = head;
    printf("Your Inputs Are : ");
    while (ptr!=NULL)
    {
        printf("%2d ",ptr->data);
        ptr=ptr->link;
    }
};


int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data=23;
    head->link=NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data=36;
    current->link=NULL;
    head->link=current;

    current = malloc(sizeof(struct node));
    current->data=93;
    current->link=NULL;

    head->link->link=current;

    count_of_nodes(head);
    print_nodes(head);
    
}