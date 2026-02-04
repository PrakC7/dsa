// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node* left;
    int data;
    struct Node* right;
};

struct Node* insert(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> left = NULL;
    newNode -> data = data;
    newNode -> right = NULL;
    return newNode;
}

struct Node* BST(struct Node* root, int data){ //root missed
    if (root == NULL){
        return insert(data);
    }
    else{
        if(data<root->data){
            root -> left = BST(root -> left,data);
        }
        else{
            root -> right = BST(root -> right,data);
        }
    }
    return root;
};

void Inorder(struct Node *root){
    if (root == NULL){
        return;
    }
    else{
        Inorder(root -> left);
        printf("%d ",root -> data);
        Inorder(root -> right);
    }
};


int main() {
    struct Node*root = NULL;
    int data;
    printf("Enter the 6 values:\n");
    for(int i = 1; i<6 ; i++){
        scanf("%d ",&data);
        root = BST(root, data);
    }
    printf("\nBST Inorder value is:\n");
    Inorder(root);
}
