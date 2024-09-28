#include <stdio.h>
#include <stdlib.h>

// Define a structure for the expression tree node
struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(char data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void preOrder(struct TreeNode* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct TreeNode* root) {
    if(root != NULL){
        inOrder(root->left);
        printf("%c ",root->data);
        inOrder(root->right);
    }
}

void postOrder(struct TreeNode* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%c ", root->data);
    }
}

int main() {
    struct TreeNode *root = createNode('+');
    root->left = createNode('a');
    
    root->right = createNode('*');
    root->right->left = createNode('-');
    root->right->left->left = createNode('/');
    root->right->left->left->left = createNode('b');
    root->right->left->left->right = createNode('c');
    root->right->left->right = createNode('d');

    root->right->right = createNode('-');
    root->right->right->left = createNode('e');
    root->right->right->right = createNode('/');
    root->right->right->right->left = createNode('*');
    root->right->right->right->left->left = createNode('f');
    root->right->right->right->left->right = createNode('g');
    root->right->right->right->right = createNode('h');

    // Print pre-order expression
    printf("Pre-order expression: ");
    preOrder(root);
    printf("\n");

    // Print post-order expression
    printf("Post-order expression: ");
    postOrder(root);
    printf("\n");

    printf("In-order expression: ");
    inOrder(root);
    printf("\n");

    return 0;
}
