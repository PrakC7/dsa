#include <stdio.h>

int graph[5][5],visited[5],queue[10];

void bfs(int start){
    int front=0,rear=0;
    queue[rear++]=start;
    visited[start]=1;

    while(front<rear){
        int u=queue[front++];
        printf("%d ",u);
        for(int i=0;i<5;i++){
            if(graph[u][i]&&!visited[i]){
                queue[rear++]=i;
                visited[i]=1;
            }
        }
    }
}

int main(){
    graph[0][1]=graph[1][3]=1;
    bfs(0);
}
