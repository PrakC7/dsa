#include <stdio.h>

int graph[5][5],visited[5];

void dfs(int u){
    visited[u]=1;
    for(int i=0;i<5;i++){
        if(graph[u][i]&&!visited[i])
            dfs(i);
    }
}

int main(){
    graph[0][1]=1;
    graph[2][3]=1;

    int count=0;

    for(int i=0;i<5;i++){
        if(!visited[i]){
            dfs(i);
            count++;
        }
    }

    printf("%d",count);
}
