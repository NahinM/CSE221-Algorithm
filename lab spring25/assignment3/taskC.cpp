#include <stdio.h>
#define ll long long

ll fastMod(ll a, ll b){
    if(b<=1) return a;

    ll x = fastMod(a,b>>1);
    return (((x*x)%107)*(b&1?a:1))%107;
}

int main(){
    freopen("input.txt","r",stdin);
    ll a,b;
    scanf("%lld %lld",&a,&b);
    printf("%lld\n",fastMod(a%107,b));
}