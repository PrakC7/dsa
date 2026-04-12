#include <stdio.h>

int parent[10];

int find(int i){
    while(parent[i]) i=parent[i];
    return i;
}

void unite(int i,int j){
    parent[i]=j;
}

int main(){
    int graph[3][3]={{0,1,4},{1,0,2},{4,2,0}},cost=0;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(graph[i][j]){
                int u=find(i),v=find(j);
                if(u!=v){
                    cost+=graph[i][j];
                    unite(u,v);
                }
            }
        }
    }

    printf("%d",cost);
}
