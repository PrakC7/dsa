#include <stdio.h>
#include <string.h>
#define MAX 50

char X[MAX], Y[MAX];
int table[MAX][MAX];

int DP_LCS(int m , int n){
    if(m == 0 || n == 0){
        return 0;
    }

    if(table[m][n] != -1){
        return table[m][n];
    }

    if(X[m-1] == Y[n-1]){
        table[m][n] = 1 + DP_LCS(m-1, n-1);
    } 
    else{
        int a = DP_LCS(m, n-1);
        int b = DP_LCS(m-1, n);
        table[m][n] = (a > b) ? a : b;
    }

    return table[m][n];
}

int main() {
    strcpy(X, "ABABABABAA");
    strcpy(Y, "BABABA");

    int m = strlen(X);
    int n = strlen(Y);

    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            table[i][j] = -1;
        }
    }

    printf("Length of LCS is %d", DP_LCS(m,n));
    return 0;
}
