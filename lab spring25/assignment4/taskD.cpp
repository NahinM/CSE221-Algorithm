#include <stdio.h>
#define rept(i,n) for(int i=0;i<n;i++)

void solve(){
    int n,m,odd=0;
    scanf("%d %d",&n,&m);
    int a,deg[n+1]={};
    rept(i,m*2) {
        scanf("%d",&a);
        deg[a]++;
        deg[a]&1?odd++:odd--;
    }
    printf((odd!=2 && odd!=0)?"NO\n":"YES\n");
}

int main(){
    freopen("input.txt","r",stdin);
    int t{1};
    scanf("%d",&t);
    while (t--) solve();
    return 0;
}