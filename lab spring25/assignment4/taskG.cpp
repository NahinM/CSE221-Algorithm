#include <stdio.h>
#include <vector>

#define vi std::vector<int>
#define br printf("\n")
#define rept(i,a,b) for(int i=a;i<b;i++)

int gcd(int x,int y){
    if(x>y) std::swap(x,y);
    if(y%x==0) return x;
    else return gcd(y%x,x);
}

bool gcd1(int x, int y){
    if(x==y) return false;
    return gcd(x,y)==1;
}

void solve(){
    int n,q;
    scanf("%d %d",&n,&q);
    vi graph[n+1];
    std::vector<bool> dp[n+1];
    int x,k;
    while(q--){
        scanf("%d %d",&x,&k);
        int f=graph[x].size();
        if(f<k){
            for(int i=f==0?1:graph[x].back()+1;i<=n && f<k;i++) if(gcd1(x,i)){graph[x].push_back(i);f++;}
        }
        printf("%d\n",(f>=k)?graph[x][k-1]:-1);
    }
}

int main(){
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}