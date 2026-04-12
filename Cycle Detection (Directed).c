#include <stdio.h>

int graph[5][5],visited[5],rec[5];

int dfs(int u){
    visited[u]=1;
    rec[u]=1;

    for(int i=0;i<5;i++){
        if(graph[u][i]){
            if(!visited[i] && dfs(i)) return 1;
            else if(rec[i]) return 1;
        }
    }

    rec[u]=0;
    return 0;
}

int main(){
    graph[0][1]=graph[1][2]=graph[2][0]=1;
    printf("%d",dfs(0));
}
