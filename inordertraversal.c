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

void Inorder(struct Node *root){
    struct Node* stack[20];
    int top = -1;
    while(root != NULL || top != -1){
        if(root != NULL){
            stack[++top] = root;
            root = root -> left;
        }
        else{
            root=stack[top--];
            printf("%d ", root->data);
            root=root->right;
        }
    }
}

// void Inorder(struct Node* root){
//     if(root == NULL){
//         return;
//     }
//     Inorder(root->left);
//     printf("%d ", root->data);
//     Inorder(root->right);
// }



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


    return 0;
}
