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

int height(struct node* root){
    if(root == NULL) return 0;
    
    int leftheight = height(root->left);
    int rightheight = height(root->right);

    if(leftheight>rightheight) return leftheight+1;
    else return rightheight+1;
}

int IsBalanced = 0;
int balance(struct node* root){
    if(root==NULL) return;

    int lh = balance(root->left);
    int rh = balance(root->right);

    if(lh-rh>1 || lh-rh<-1){
        IsBalanced = 1;
        return;
    }
    else{
        IsBalanced =0;
        return;
    }
}

int Height = 0;
int randomHeight(struct node* root, int value){
    if(root==NULL) return 0;
    else if(root->data == value) return Height+1;
    else if(root->data < value){
        Height++;
        return randomHeight(root->right,value);
    }
    else if(root->data > value){
        Height++;
        return randomHeight(root->left,value);
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

    printf("Height Of the Binary Search tree is : %d\n",height(root));

    printf("Write The elment of which You want to find height : ");
    int temp;
    scanf("%d",&temp);
    printf("Height of Given element is : %d\n",randomHeight(root,temp));

    balance(root);

    if(IsBalanced==1) printf("Tree Is not balanced.\n");
    else printf("Tree is Balanced.\n");

}

