#include <stdio.h>

int graph[5][5],visited[5];

int dfs(int u,int parent){
    visited[u]=1;
    for(int i=0;i<5;i++){
        if(graph[u][i]){
            if(!visited[i]){
                if(dfs(i,u)) return 1;
            }
            else if(i!=parent) return 1;
        }
    }
    return 0;
}

int main(){
    graph[0][1]=graph[1][0]=1;
    graph[1][2]=graph[2][1]=1;
    graph[2][0]=graph[0][2]=1;
    printf("%d",dfs(0,-1));
}
