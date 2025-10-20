#include <stdio.h>
#define rept(i,a,b) for(int i=a;i<b;i++)

int main(){
    freopen("input.txt","r",stdin);
    int n,m,a;
    scanf("%d %d",&n,&m);
    int diff[n+1]={};
    rept(i,0,m) {scanf("%d",&a);diff[a]--;}
    rept(i,0,m) {scanf("%d",&a);diff[a]++;}
    rept(i,1,n+1) printf("%d ",diff[i]);
    printf("\n");
    return 0;
}