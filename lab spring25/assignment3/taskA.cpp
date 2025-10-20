#include <stdio.h>
#include <vector>
using namespace std;

#define vi vector<int>
#define rept(i,a,b) for(int i=a;i<b;i++)
#define br printf("\n")
#define ll long long
#define vll vector<ll>

//global var
ll inversions = 0;

vll copy(const vll &arr,int l, int r){
    vll x;
    for(int i=l;i<r;i++) x.push_back(arr[i]);
    return x;
}

vll marge(vll &arr, const vll &a, const vll &b){
    int i=0,j=0,la=a.size(),lb=b.size();
    vll res;
    while (i<la && j<lb)
    {
        if(a[i]<b[j]) res.push_back(a[i++]);
        else {
            res.push_back(b[j++]);
            inversions += (la-i);
        }
    }
    while (i<la) res.push_back(a[i++]);
    while (j<lb) res.push_back(b[j++]);
    return res;
}

vll mergeSort(vll &arr){
    if(arr.size()<=1) return arr;
    int sz=arr.size();
    int mid = sz>>1;
    
    vll a = copy(arr,0,mid); 
    vll aa = mergeSort(a);
    vll b = copy(arr,mid,sz); 
    vll bb = mergeSort(b);
    return marge(arr,aa,bb);
}

void solve(){
    inversions = 0;
    int n;
    scanf("%d",&n);
    vll arr(n);
    for(ll &i:arr) scanf("%lld",&i);
    vll arr2 = mergeSort(arr);
    printf("%lld\n",inversions);
    for(ll i:arr2) printf("%lld ",i);br;
}

int main(){
    freopen("input.txt","r",stdin);
    int t =1;
    // scanf("%d",&t);
    while (t--) solve();
}