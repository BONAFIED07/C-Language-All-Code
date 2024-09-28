#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	char alpha;
	char *string;
	struct node *link;
};

void print_ll(struct node *head);

int main(){
	struct node *head = malloc(sizeof(struct node));
	head->data = 4;
	head->alpha = 'a';
	head->string = "1st_Node";
	head->link = NULL;

	struct node *current = malloc(sizeof(struct node));
	current->data = 13;
	current->alpha = 'z';
	current->string = "2nd_Node";
	current->link = NULL;
	head->link = current;

	current = malloc(sizeof(struct node));
	current->data = -7;
	current->alpha = 't';
	current->string = "3rd Node";
	current->link = NULL;
	head->link->link = current;

	current = malloc(sizeof(struct node));
        current->data = 44;
        current->alpha = 'q';
	current->string = "4rd_Node";
        current->link = NULL;
        head->link->link->link = current;

	current = malloc(sizeof(struct node));
        current->data = 0;
        current->alpha = 'u';
	current->string = "5th_Node";
        current->link = NULL;
        head->link->link->link->link = current;
	print_ll(head);

}
    
void print_ll(struct node *head){
	if(head == NULL){
		return;
	}
	else{
		while(head!=NULL){
        if (head->alpha=='q')
        {
            
        }
        else{
		    printf("%2d ",head->data);
			printf("%2c ",head->alpha);
			printf("%s",head->string);
			printf("\n");
        }
        head=head->link;
        }
		}
	}

