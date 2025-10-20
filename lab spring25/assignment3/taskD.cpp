#include <stdio.h>
#include <map>
using namespace std;
#define ull unsigned long long
#define mp map<ull,ull>

ull fastMod(mp &dp, ull a, ull n, ull m){
    if(n<=1) return a;
    if(dp.find(n)!=dp.end()) return dp[n];
    ull x = fastMod(dp,a,n>>1,m);
    dp[n>>1] = x;
    if(n&1){
        return (((x*x)%m)*a)%m;
    }else{
        return (x*x)%m;
    }
}

ull driftMod(mp &dp,ull a, ull n, ull m){
    if(n<=1) return a;

    ull sln = driftMod(dp,a,n>>1,m)%m;
    ull an = fastMod(dp,a,n>>1,m);
    ull ann = fastMod(dp,a,n,m);
    if(n&1){
        return (sln+an*sln + ann)%m;
    }else{
        return (sln+an*sln)%m;
    }
}

void solve(){
    ull a,n,m;
    mp dp;
    scanf("%llu %llu %llu",&a,&n,&m);
    printf("%llu\n",driftMod(dp,a%m,n,m));
}

int main(){
    freopen("input.txt","r",stdin);

    int t=1;
    scanf("%d",&t);
    while(t--)solve();
}