#include <stdio.h>

#define br printf("\n")
#define rept(i,a,b) for(int i=a;i<b;i++)


void solve(){
    int n,m;
    int matrix[100+1][100+1]={};
    scanf("%d",&n);
    int v;
    rept(i,0,n){
        scanf("%d",&m);
        while (m--) {
            scanf("%d",&v);
            matrix[i][v] = 1;
            matrix[v][i] = 1;
        }
    }
 
    rept(i,0,n) {
        rept(j,0,n) {
            printf("%d ",matrix[i][j]);
        }br;
    }
}

int main(){
    freopen("input.txt","r",stdin);
    int t=1;
    // scanf("%d",&t);
    while (t--) solve();
    return 0;
}