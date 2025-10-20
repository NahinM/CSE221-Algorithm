#include <stdio.h>

int search(int x, int y, int arr[],int n){
    int lw=0,hi=n-1,head=0,end=0,mid;
    if(arr[hi]<x || y<arr[lw]) return 0;
    if(x<arr[lw] && arr[hi]<y) return n;
    while (lw<=hi)
    {
        mid = (hi+lw)>>1;
        if(arr[mid]<x) lw = mid+1;
        else {
            head = mid;
            hi = mid-1;
        }
    }
    
    lw = 0; hi = n-1;
    while (lw<=hi)
    {
        mid = (hi+lw)>>1;
        if(arr[mid]<=y) {
            end = mid;
            lw = mid+1;
        } else hi = mid-1;
    }

    return end-head+1;
}

void solve(){
    int n,q;
    scanf("%d %d",&n,&q);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    int x,y;
    for(int i=0;i<q;i++){
        scanf("%d %d", &x, &y);
        printf("%d\n",search(x,y,arr,n));
    }
}

int main(){
    freopen("input.txt","r",stdin);

    int t=1;
    // scanf("%d", &t);
    while (t--) solve();
}