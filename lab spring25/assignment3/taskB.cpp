#include <stdio.h>
#define ll long long

int main(){
    freopen("input.txt","r",stdin);
    ll n;
    scanf("%lld",&n);
    ll j,i;
    scanf("%lld",&i); n--;
    ll max = i;

    while (n--){
        scanf("%lld",&j);
        ll res = i+(j*j);
        if(res>max) max = res;
        if(i<j) i = j;
    }
    printf("%lld\n",max);
}