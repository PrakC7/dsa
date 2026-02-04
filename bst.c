#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node* left;
    int data;
    struct Node* right;
};

struct Node* insert(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->left = NULL;
    newNode->data = data;
    newNode->right = NULL;
    return newNode;
}

struct Node* BST(struct Node* root, int data){
    if(root == NULL){
        return insert(data);
    }
    if(data < root->data){
        root->left = BST(root->left, data);
    } else {
        root->right = BST(root->right, data);
    }
    return root;
}

int BST_height(struct Node* root){
    if(root == NULL){
        return -1;
    }
    int lh = BST_height(root->left);
    int rh = BST_height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

int count_nodes(struct Node* root){
    if(root == NULL){
        return 0;
    }
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

void Inorder(struct Node* root){
    if(root == NULL){
        return;
    }
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}

int main(){
    struct Node* root = NULL;
    int data;
    printf("Enter the 5 values:\n");
    for(int i = 0; i < 5; i++){
        scanf("%d", &data);
        root = BST(root, data);
    }
    printf("\nBST Inorder value is:\n");
    Inorder(root);
    printf("\nBST height value is: %d", BST_height(root));
    printf("\nNumber of Nodes in BST: %d", count_nodes(root));
    return 0;
}
