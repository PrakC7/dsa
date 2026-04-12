#include <stdio.h>

int heap[100],size=0;

void push(int value){
    heap[size]=value;
    int i=size;
    size++;

    while(i>0){
        int parent=(i-1)/2;
        if(heap[parent]<heap[i]){
            int t=heap[parent];
            heap[parent]=heap[i];
            heap[i]=t;
            i=parent;
        }else break;
    }
}

int pop(){
    if(size==0) return -1;

    int top=heap[0];
    heap[0]=heap[size-1];
    size--;

    int i=0;

    while(1){
        int left=2*i+1,right=2*i+2,largest=i;

        if(left<size && heap[left]>heap[largest])
            largest=left;
        if(right<size && heap[right]>heap[largest])
            largest=right;

        if(largest!=i){
            int t=heap[i];
            heap[i]=heap[largest];
            heap[largest]=t;
            i=largest;
        }else break;
    }

    return top;
}

int main(){
    push(5);
    push(10);
    push(3);
    printf("%d ",pop());
    printf("%d ",pop());
}
