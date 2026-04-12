#include <stdio.h>
#include <stdlib.h>

struct Node{int value;struct Node* left;struct Node* right;};

struct Node* insert(struct Node* r,int v){
    if(r==NULL){
        struct Node* n=malloc(sizeof(struct Node));
        n->value=v;n->left=n->right=NULL;
        return n;
    }
    if(v<r->value) r->left=insert(r->left,v);
    else r->right=insert(r->right,v);
    return r;
}

struct Node* min(struct Node* r){
    while(r->left) r=r->left;
    return r;
}

struct Node* del(struct Node* r,int k){
    if(r==NULL) return r;
    if(k<r->value) r->left=del(r->left,k);
    else if(k>r->value) r->right=del(r->right,k);
    else{
        if(r->left==NULL) return r->right;
        if(r->right==NULL) return r->left;
        struct Node* t=min(r->right);
        r->value=t->value;
        r->right=del(r->right,t->value);
    }
    return r;
}

void inorder(struct Node* r){
    if(r){
        inorder(r->left);
        printf("%d ",r->value);
        inorder(r->right);
    }
}

int main(){
    struct Node* r=NULL;
    r=insert(r,5);
    r=insert(r,3);
    r=insert(r,7);
    r=del(r,3);
    inorder(r);
}
