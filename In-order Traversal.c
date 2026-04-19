#include <stdio.h>
#include <stdlib.h>

struct Node{int value;struct Node* left;struct Node* right;};

struct Node* create(int v){
    struct Node* n=malloc(sizeof(struct Node));
    n->value=v;n->left=n->right=NULL;
    return n;
}

void inorder(struct Node* r){
    if(r==NULL) return;
    inorder(r->left);
    printf("%d ",r->value);
    inorder(r->right);
}

int main(){
    int arr[10];
    struct Node* nodes[10];

    printf("Enter 10 digits:\n");
    for(int i=0;i<10;i++){
        scanf("%d",&arr[i]);
        nodes[i]=create(arr[i]);
    }

    for(int i=0;i<10;i++){
        int left=2*i+1;
        int right=2*i+2;

        if(left<10) nodes[i]->left=nodes[left];
        if(right<10) nodes[i]->right=nodes[right];
    }

    struct Node* r=nodes[0];

    inorder(r);
}
