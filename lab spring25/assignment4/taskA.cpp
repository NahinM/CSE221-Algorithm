#include <stdio.h>
#include <vector>

#define br printf("\n")
#define rept(i,a,b) for(int i=a;i<b;i++)


void solve(){
    int n,m;
    int matrix[100+1][100+1]={};
    scanf("%d %d",&n, &m);
    int u,v,w;
    while (m--){
        scanf("%d %d %d",&u,&v,&w);
        matrix[u][v] = w;
    }
 
    rept(i,1,n+1) {
        rept(j,1,n+1) {
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