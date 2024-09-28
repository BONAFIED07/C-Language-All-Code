#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createnode(int value){
    struct node* temp = malloc(sizeof(struct node));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

struct node* insert(struct node* root, int value){      //  traversal me return aayega conditions me aayega
    if(root==NULL){
        return createnode(value);
    }
    else if(root->data < value){
        root->right = insert(root->right,value);
    }
    else{
        root->left = insert(root->left,value);
    }
}

void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void leafdel(struct node* root){
    if(root == NULL){
        return;
    }
    if(root->left!= NULL && root->left->left == NULL && root->left->right == NULL){
        free(root->left);
        root->left = NULL;
    }
    if(root->right!= NULL && root->right->left == NULL && root->right->right == NULL){
        free(root->right);
        root->right = NULL;
    }

    leafdel(root->left);
    leafdel(root->right);
}

int main(){
    struct node* root = NULL;
    root = insert(root,10);
    insert(root, 8);
    insert(root, 12);
    insert(root, 6);
    insert(root, 9);
    insert(root, 11);
    insert(root, 13);

    printf("Your Inorder Traversal Is = ");
    inorder(root);
    printf("\n");

    leafdel(root);

    printf("Your Inorder Traversal Is = ");
    inorder(root);
    printf("\n");
}