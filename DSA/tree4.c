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

// Inorder traversal (left-root-right)
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void mirror(struct node* root) {
    if (root == NULL)
        return;

    // Swap left and right subtrees                  Traversal me return nahi aayega condition me aayega
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively mirror left and right subtrees
    mirror(root->left);
    mirror(root->right);
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

    printf("Post Tree Inorder Is = ");
    postorder(root);
    printf("\n");

    mirror(root);

    printf("Your Inorder Traversal Is = ");
    inorder(root);
    printf("\n");
}

