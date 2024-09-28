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

// Preorder traversal (root-left-right)
void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal (left-right-root)
void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int countnodes(struct node* root){
    if(root == NULL) return 0;
    else return 1 + countnodes(root->left) + countnodes(root->right);
}

int search(struct node* root, int value){
    if(root==NULL) return 0;
    else if(root->data == value) return 1;
    else if(root->data < value) return search(root->right,value);
    else if(root->data > value) return search(root->left,value);
}

struct node* del_last(struct node* root, int value){
    if(root->left->data == value || root->right->data == value){
        return root;
    }
    
    else if(root->data < value) return del_last(root->right,value);
    else if(root->data > value) return del_last(root->left,value);
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

    printf("Your Postorder Traversal Is = ");
    preorder(root);
    printf("\n");

    printf("Your Preorder Traversal Is = ");
    postorder(root);
    printf("\n");

    printf("Number of Node Are = %d\n",countnodes(root));

    printf("Which Number Do you want To seach : ");
    int temp;
    scanf("%d",&temp);
    if(search(root,temp)==1) printf("Found\n");
    else printf("Not Found\n");

    printf("Enter Last element You Want to delete :  ");
    int num;
    scanf("%d",&num);
    struct node* del = del_last(root,num);
  
    if(del->data < num){
        del->right=NULL;
    }
    else del->left = NULL;

    printf("Your Inorder Traversal Is = ");
    inorder(root);
    printf("\n");

}

