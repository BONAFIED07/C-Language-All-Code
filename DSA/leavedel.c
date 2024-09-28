#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left;
    struct node*right;
};
struct node*newnode(int key){
     struct node*n=(struct node*)malloc(sizeof(struct node));
        n->data=key;
        n->left=NULL;
        n->right=NULL;
        return n;
}
void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
struct node*bstinsert(struct node*node,int key){
    if(node==NULL){
        return newnode(key);
    }
    if(key>node->data){
       node->right= bstinsert(node->right, key);
    }
    else
         node->left= bstinsert(node->left, key);
    
    return node;
}
void leafdelete(struct node* root) {
    if (root == NULL) {
        return;
    }
    else if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) {
        root->left = NULL;
    }
    else if (root->right != NULL && root->right->left == NULL && root->right->right == NULL) {
        root->right = NULL;
    }
    leafdelete(root->left);
    leafdelete(root->right);
}

int main(){
     struct node*root;
     root=NULL;
     root=bstinsert(root,50);
     bstinsert(root,90);
     bstinsert(root,60);
     bstinsert(root,40);
     bstinsert(root,20);
     bstinsert(root,10);
     bstinsert(root,45);
     inorder(root);
     leafdelete(root);
     printf("\n");
     inorder(root);
     return 0;



}