#include <stdio.h>

void heapify(int a[],int n,int i){
    int l=2*i+1,r=2*i+2,m=i;
    if(l<n&&a[l]>a[m]) m=l;
    if(r<n&&a[r]>a[m]) m=r;
    if(m!=i){
        int t=a[i];a[i]=a[m];a[m]=t;
        heapify(a,n,m);
    }
}

int main(){
    int a[5]={4,10,3,5,1},n=5;
    for(int i=n/2-1;i>=0;i--) heapify(a,n,i);
    for(int i=n-1;i>=0;i--){
        int t=a[0];a[0]=a[i];a[i]=t;
        heapify(a,i,0);
    }
    for(int i=0;i<n;i++) printf("%d ",a[i]);
}
