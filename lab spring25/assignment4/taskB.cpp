#include <stdio.h>
// #include <vector>

#define br printf("\n")
// #define pii std::pair<int,int>
// #define vpii std::vector<pii>
// #define vi std::vector<int>
#define rept(i,a,b) for(int i=a;i<b;i++)


// void solve(){
//     int n,m;
//     std::vector<vpii> graph(100+1);
//     scanf("%d %d",&n, &m);
//     int a;
//     vi u,v,w;
//     rept(i,0,m){scanf("%d",&a);u.push_back(a);}
//     rept(i,0,m){scanf("%d",&a);v.push_back(a);}
//     rept(i,0,m){scanf("%d",&a);w.push_back(a);}
//     rept(i,0,m){
//         graph[u[i]].push_back({v[i],w[i]});
//     }

//     rept(i,1,n+1){
//         printf("%d: ",i);
//         for(pii &v:graph[i]) printf("(%d,%d) ",v.first,v.second);br;
//     }
// }

void solve(){
    int n,m;
    int matrix[100+1][100+1]={},u[100+1]={},v[100+1]={},w[100+1]={};
    scanf("%d %d",&n, &m);
    int a=0; rept(i,0,m) scanf("%d",&u[a++]);
    a=0; rept(i,0,m) scanf("%d",&v[a++]);
    a=0; rept(i,0,m) scanf("%d",&w[a++]);
    a=0; rept(i,0,m) {matrix[u[a]][v[a]] = w[a];a++;}
 
    rept(i,1,n+1) {
        for(int j=0;j<n+1 && ;j++) {
            printf("%d ",matrix[i][j]);
        }br;
    }
}

int main(){
    freopen("input.txt","r",stdin);
    int t=1;
    // scanf("%d",&t);
    while (t--) solve();
    return 0;
}