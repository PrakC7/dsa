#include <stdio.h>

#define INF 999

int dist[5],visited[5];

int main(){
    int graph[3][3]={{0,1,4},{1,0,2},{4,2,0}};

    for(int i=0;i<3;i++){
        dist[i]=INF;
        visited[i]=0;
    }

    dist[0]=0;

    for(int i=0;i<3;i++){
        int u=-1;

        for(int j=0;j<3;j++){
            if(!visited[j] && (u==-1 || dist[j]<dist[u]))
                u=j;
        }

        visited[u]=1;

        for(int j=0;j<3;j++){
            if(dist[u]+graph[u][j]<dist[j])
                dist[j]=dist[u]+graph[u][j];
        }
    }

    for(int i=0;i<3;i++)
        printf("%d ",dist[i]);
}
