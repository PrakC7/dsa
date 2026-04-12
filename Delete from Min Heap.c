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

void heapify(int i){
    int left=2*i+1,right=2*i+2,smallest=i;

    if(left<size && heap[left]<heap[smallest])
        smallest=left;
    if(right<size && heap[right]<heap[smallest])
        smallest=right;

    if(smallest!=i){
        int t=heap[i];
        heap[i]=heap[smallest];
        heap[smallest]=t;
        heapify(smallest);
    }
}

void deleteMin(){
    if(size==0) return;

    heap[0]=heap[size-1];
    size--;
    heapify(0);
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

    deleteMin();
    display();
}
