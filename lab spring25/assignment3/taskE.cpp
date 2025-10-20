#include <stdio.h>
#define ll long long

void order(ll *arr,int lw,int hi){
    if(hi<lw) return;
    ll mid = (lw+hi)>>1;
    printf("%lld ",arr[mid]);
    order(arr,lw,mid-1);
    order(arr,mid+1,hi);
}

int main(){
    freopen("input.txt","r",stdin);
    ll n;
    scanf("%lld",&n);
    ll arr[n];
    for(int i=0;i<n;i++) scanf("%lld",&arr[i]);
    order(arr,0,n-1);
    printf("\n");
}