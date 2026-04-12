#include <stdio.h>
#include <stdlib.h>

struct Node{int value;struct Node* left;struct Node* right;};

int max(int a,int b){return a>b?a:b;}

int height(struct Node* r){
    if(r==NULL) return 0;
    return 1+max(height(r->left),height(r->right));
}

int main(){
    struct Node a={1,NULL,NULL};
    struct Node b={2,NULL,NULL};
    struct Node c={3,&a,&b};
    printf("%d",height(&c));
}
