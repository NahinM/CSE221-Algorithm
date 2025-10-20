#include <stdio.h>
#define br printf("\n")

void solve(){
    int n,m;
    scanf("%d",&n);
    int a1[n];
    for(int i=0;i<n;i++) scanf("%d",&a1[i]);
    scanf("%d",&m);
    int a2[m];
    for(int i=0;i<m;i++) scanf("%d",&a2[i]);

    int arr[n+m],at=0,i=0,j=0;
    while (i<n && j<m)
    {
        if(a1[i]<a2[j]){
            printf("%d ",a1[i++]);
        }else{
            printf("%d ",a2[j++]);
        }
    }

    for(i;i<n;i++) printf("%d ",a1[i]);
    for(j;j<m;j++) printf("%d ",a2[j]);
    br;
}

int main(){
    freopen("input.txt","r",stdin);
    solve();
}