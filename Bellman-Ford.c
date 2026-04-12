#include <stdio.h>

#define INF 999

int main(){
    int edges[3][3]={{0,1,1},{1,2,2},{0,2,4}};
    int dist[3]={0,INF,INF};

    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            int u=edges[j][0],v=edges[j][1],w=edges[j][2];
            if(dist[u]+w<dist[v])
                dist[v]=dist[u]+w;
        }
    }

    for(int i=0;i<3;i++)
        printf("%d ",dist[i]);
}
