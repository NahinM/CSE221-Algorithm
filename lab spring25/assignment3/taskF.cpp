#include <stdio.h>
#include <vector>
using namespace std;
#define vi vector<int>
#define br printf("\n")

int findRt(vi &a, int r,int lw, int hi){
    for(int i=lw; i<=hi; i++) if(a[i]==r) return i;
    return -1;
}

void postOrder(vi &a, vi &b, int prelw, int prehi,int inlw, int inhi){
    if(prelw>prehi) return;
    if(prelw==prehi){
        printf("%d ",b[prelw]);
        return;
    }
    int r = b[prelw];
    int in_ri = findRt(a,r,inlw,inhi);
    int lsz = in_ri-inlw, rsz = inhi-in_ri;
    postOrder(a,b,prelw+1,lsz+prelw,inlw,in_ri-1);
    postOrder(a,b,prelw+1+lsz,prehi,in_ri+1,inhi);
    printf("%d ",r);
}

int main(){
    freopen("input.txt","r",stdin);
    int n;
    scanf("%d",&n);
    vi a(n),b(n); // inorder a, pre-order b
    for(int &i:a) scanf("%d",&i);
    for(int &i:b) scanf("%d",&i);
    postOrder(a,b,0,a.size()-1,0,a.size()-1);br;
}