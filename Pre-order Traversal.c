#include <stdio.h>
#include <stdlib.h>

struct Node{int value;struct Node* left;struct Node* right;};

struct Node* create(int v){
    struct Node* n=malloc(sizeof(struct Node));
    n->value=v;n->left=n->right=NULL;
    return n;
}

void preorder(struct Node* r){
    if(r==NULL) return;
    printf("%d ",r->value);
    preorder(r->left);
    preorder(r->right);
}

int main(){
    struct Node* r=create(1);
    r->left=create(2);
    r->right=create(3);
    preorder(r);
}
