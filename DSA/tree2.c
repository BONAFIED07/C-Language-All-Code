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

int max(struct node* root){
    if(root == NULL) return -1;
    else if(root->right == NULL) return root->data;
    return max(root->right);
}

int min(struct node* root){
    if(root == NULL) return -1;
    else if(root->left == NULL) return root->data;
    return min(root->left);
}

int Max(struct node *root){
    while(root->right!=NULL){
        root = root->right;
    }
    return root->data;
}

int Min(struct node *root){
    while(root->left!=NULL){
        root = root->left;
    }
    return root->data;
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

    printf("Max : %d and Min : %d\n",min(root),max(root));
    printf("Max : %d and Min : %d\n",Min(root),Max(root));

}

