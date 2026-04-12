#include <stdio.h>

#define INF 999

int main(){
    int graph[3][3]={{0,1,4},{1,0,2},{4,2,0}};
    int visited[3]={0},cost=0;

    visited[0]=1;

    for(int e=0;e<2;e++){
        int min=INF,x,y;

        for(int i=0;i<3;i++){
            if(visited[i]){
                for(int j=0;j<3;j++){
                    if(!visited[j] && graph[i][j]<min){
                        min=graph[i][j];
                        x=i;
                        y=j;
                    }
                }
            }
        }

        cost+=min;
        visited[y]=1;
    }

    printf("%d",cost);
}
