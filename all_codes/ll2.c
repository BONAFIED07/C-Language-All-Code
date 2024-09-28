#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    char alpha;
    char *string;
    struct node *link;
};

void print_node(struct node *head);

void input(struct node *head);

int main() {
    struct node *head = malloc(sizeof(struct node));
    struct node *a = malloc(sizeof(struct node));
    struct node *b = malloc(sizeof(struct node));
    struct node *c = malloc(sizeof(struct node));
    struct node *d = malloc(sizeof(struct node));

    head->link = a;
    a->link = b;
    b->link = c;
    c->link = d;
    d->link = NULL;

    input(head);
    print_node(head);

    // Free allocated memory
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->link;
        free(temp->string);
        free(temp);
    }

    return 0;
}

void input(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("Write Your Input : ");
        current->string = malloc(256); // Adjust the size as needed
        scanf("%d %c %s", &(current->data), &(current->alpha), current->string);
        current = current->link;
    }
}

void print_node(struct node *head) {
    if (head == NULL) {
        printf("Empty\n");
    } else {
        struct node *p = head;
        while (p != NULL) {
            printf("%2d ", p->data);
            printf("%2c ", p->alpha);
            printf("%s", p->string);
            printf("\n");
            p = p->link;
        }
    }
}
