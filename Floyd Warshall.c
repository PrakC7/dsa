#include <stdio.h>

int dist[5][5];

int main(){
    int graph[3][3]={{0,1,4},{1,0,2},{4,2,0}};

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            dist[i][j]=graph[i][j];

    for(int k=0;k<3;k++)
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(dist[i][k]+dist[k][j]<dist[i][j])
                    dist[i][j]=dist[i][k]+dist[k][j];

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            printf("%d ",dist[i][j]);
        printf("\n");
    }
}
