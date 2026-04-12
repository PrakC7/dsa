#include <stdio.h>

int main(){
    int graph[3][3]={{0,1,1},{1,0,1},{1,1,0}};
    for(int i=0;i<3;i++){
        int degree=0;
        for(int j=0;j<3;j++)
            degree+=graph[i][j];
        printf("%d ",degree);
    }
}
