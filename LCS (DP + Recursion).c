#include <stdio.h>
#include <string.h>

int table[10][10];

int max(int a,int b){return a>b?a:b;}

int lcs(char X[],char Y[],int i,int j){
    if(i==0||j==0) return 0;

    if(table[i][j]!=-1) return table[i][j];

    if(X[i-1]==Y[j-1])
        table[i][j]=1+lcs(X,Y,i-1,j-1);
    else
        table[i][j]=max(lcs(X,Y,i-1,j),lcs(X,Y,i,j-1));

    return table[i][j];
}

int main(){
    char X[]="ABCBDAB",Y[]="BDCABA";
    int m=strlen(X),n=strlen(Y);

    for(int i=0;i<=m;i++)
        for(int j=0;j<=n;j++)
            table[i][j]=-1;

    printf("%d",lcs(X,Y,m,n));
}
