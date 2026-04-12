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

struct Node* search(struct Node* r,int k){
    if(r==NULL||r->value==k) return r;
    if(k<r->value) return search(r->left,k);
    return search(r->right,k);
}

int main(){
    struct Node* r=NULL;
    r=insert(r,5);
    r=insert(r,3);
    r=insert(r,7);
    printf("%d",search(r,7)!=NULL);
}
