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

int height(struct node* root){
    if(root==NULL) return 0;
    
    int lh = height(root->left);
    int rh = height(root->right);

    if(lh>rh) return lh+1;
    else return rh+1;
}

int countnodes(struct node* root){
    if(root==NULL) return 0;
    else return 1+countnodes(root->left)+countnodes(root->right);
}

int search(struct node* root,int value){
    if(root==NULL) return 0;
    else if(root->data == value) return 1;
    else if(value > root->data) return search(root->right,value);
    else return search(root->left,value);
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

    printf("Your Total Numeber of Nodes : %d\n",countnodes(root));
    printf("Height : %d\n",height(root));

    int num;
    scanf("%d",&num);
    if(search(root,num)==0) printf("Not Found\n");
    else printf("Found\n");
}