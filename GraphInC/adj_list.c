#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* createnode(int a) {
    struct node* temp = malloc(sizeof(struct node));
    temp->data = a;
    temp->link = NULL;
    return temp;
}


int main() {
    // Creating linked lists for each array element

    int u,v;
    scanf("%d %d",&u,&v);
    struct node* adj_list[u];
    struct node* copy[u];

    for(int i=0; i<u; i++){
        adj_list[i] = createnode(i);
        copy[i] = adj_list[i];
    }

    for(int i=0; i<v; i++){
        int x,y;
        scanf("%d %d",&x,&y);
        copy[x]->link = createnode(y);
        copy[x] = copy[x]->link;
    }

    printf("\nYour Adjacency List is :\n");
    for(int i=0; i<u; i++){
        struct node* temp = adj_list[i];
        printf("%d : ",temp->data);
        temp = temp->link;
        while(temp!= NULL){
            printf("%d->",temp->data);
            temp = temp->link;
        }
        printf("NULL\n");
    }

}
