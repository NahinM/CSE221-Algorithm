#include <stdio.h>

#define rept(i,a,b) for(int i=a;i<b;i++)

int N;
bool valid(int r, int c){
    return 1<=r && r<=N && 1<=c && c<=N;
}

void solve(){
    int dc[8] = {-1,-1,-1,0,0,1,1,1};
    int dr[8] = {-1,0,1,-1,1,-1,0,1};
    int R[8],C[8];
    int x,y,ttl=0,rr,cc;
    scanf("%d",&N);
    scanf("%d %d",&x,&y);
    rept(i,0,8){
        rr = x+dc[i];
        cc = y+dr[i];
        if(valid(rr,cc)){
            R[ttl]=rr;
            C[ttl]=cc;
            ttl++;
        }
    }
    printf("%d\n",ttl);
    rept(i,0,ttl) printf("%d %d\n",R[i],C[i]);
}

int main(){
    freopen("input.txt","r",stdin);
    int t=1;
    // scanf("%d",&t);
    while (t--) solve();
    return 0;
}