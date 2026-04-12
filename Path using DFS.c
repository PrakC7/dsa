#include <stdio.h>

int graph[5][5],visited[5],found=0;

void dfs(int u,int dest){
    if(u==dest){found=1;return;}
    visited[u]=1;
    for(int i=0;i<5;i++){
        if(graph[u][i]&&!visited[i])
            dfs(i,dest);
    }
}

int main(){
    graph[0][1]=graph[1][2]=1;
    dfs(0,2);
    printf("%d",found);
}
