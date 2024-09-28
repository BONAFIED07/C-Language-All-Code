#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

int count=0;
void count_nodes(struct node *head){
    struct node *ptr = head;
    if(head==NULL){
        return;
    }
    else{
        while (ptr!=NULL)
        {
            count++;
            ptr=ptr->link;
        }
        printf("Number Of Nodes Are : %d\n",count);
    }
}

void print_ll(struct node *head){
    if(head==NULL){
        printf("Nothing\n");
        return;
    }
    else{
        struct node *ptr = head;
        printf("Your Elements Are : ");
        while(ptr!=NULL){
            printf("%d ",ptr->data);
            ptr=ptr->link;
           
        }
    }
}


int main(){
    int n;
    printf("Write Number of element You Want To enter : ");
    scanf("%d",&n);
    int i=1;   
    int a,b,c;
    struct node *current;
    struct node *temp;
    struct node *head;


    while(1){
        if(i>n){
            break;
        }
            else if(i==1){
                head = malloc(sizeof(struct node));
                printf("Write the Value For Node 1 : ");
                scanf("%d",&a);
                head->data=a;
                head->link= NULL;
            }
            else if(i==2){
                current = malloc(sizeof(struct node));
                printf("Write the Value For Node %d : ",i);
                scanf("%d",&b);
                current->data = b;
                current->link= NULL;
                head->link = current;
            }
            else{
                temp = malloc(sizeof(struct node));
                printf("Write The Value for Node %d : ",i);
                scanf("%d",&c);
                temp->data=c;
                temp->link=NULL;
                current->link=temp;
                current=current->link;
            }
            i++;

        }
        count_nodes(head);
        sort_ll(head);
        print_ll(head);

}