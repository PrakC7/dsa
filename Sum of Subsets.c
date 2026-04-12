#include <stdio.h>

int set[5]={1,2,3,4,5},n=5,target=5;

void solve(int i,int sum){
    if(sum==target){
        printf("Yes\n");
        return;
    }

    if(i==n||sum>target) return;

    solve(i+1,sum+set[i]);
    solve(i+1,sum);
}

int main(){
    solve(0,0);
}
