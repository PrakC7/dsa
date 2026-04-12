#include <stdio.h>

int heap[100],size=0;

void insert(int value){
    heap[size]=value;
    int i=size;
    size++;

    while(i>0){
        int parent=(i-1)/2;
        if(heap[parent]>heap[i]){
            int t=heap[parent];
            heap[parent]=heap[i];
            heap[i]=t;
            i=parent;
        }else break;
    }
}

void display(){
    for(int i=0;i<size;i++)
        printf("%d ",heap[i]);
}

int main(){
    insert(5);
    insert(3);
    insert(8);
    insert(1);
    display();
}
