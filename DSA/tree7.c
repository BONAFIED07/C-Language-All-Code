#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int value){
    struct node* temp = malloc(sizeof(struct node));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node* insert(struct node* root, int value){
    if(root==NULL){
        return createnode(value);
    }
    else if(value < root->data){
        root->left = insert(root->left,value);
    }
    else if(value > root->data){
        root->right = insert(root->right,value);
    }
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct node* min(struct node* root){
    while(root->left != NULL) root = root->left;
    return root;
}

struct node* delete(struct node* root,int value){
    if(root==NULL) return NULL;
    else if(value < root->data) root->left = delete(root->left,value);
    else if(value > root->data) root->right = delete(root->right,value);
    else{
        // Case 1
        if(root->left == NULL && root->right == NULL) return NULL;
        // Case 2
        else if(root->left == NULL) return root->right;
        else if(root->right == NULL) return root->left;
        // Case 3
        else{
            struct node* temp = min(root->right);
            root->data = temp->data;
            root->right = delete(root->right,temp->data);
            return root;
        }
    }
}

int main(){
    struct node* root = NULL;
    root = insert(root, 10);
    insert(root, 8);
    insert(root, 12);
    insert(root, 6);
    insert(root, 9);
    insert(root, 11);
    insert(root, 13);

    printf("Your Inorder Traversal Is = ");
    inorder(root);
    printf("\n");

    int num;
    printf("Enter data You want to delete : ");
    scanf("%d",&num);
    delete(root,num);

    printf("Your Inorder Traversal Is = ");
    inorder(root);
    printf("\n");


}