#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

#define rept(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define vb vector<bool>
#define pqi priority_queue<int>
#define br printf("\n")

void print(const vector<vi> &graph,int n){
    for(int i=1;i<=n;i++){
        printf("%d: ",i);
        for(int u:graph[i]){
            printf(" -> %d",u);
        }br;
    }
}

void dfs(vector<pqi> &graph,vb &vst, int at){
    vst[at] = true;
    printf("%d ",at);
    while (!graph[at].empty())
    {
        int u = -graph[at].top(); graph[at].pop();
        if(!vst[u]) dfs(graph,vst,u);
    }
    
}

void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<pqi> graph(n+1);
    int u[m],v[m];
    rept(i,m) scanf("%d",&u[i]);
    rept(i,m) scanf("%d",&v[i]);
    rept(i,m) {
        graph[u[i]].push(-v[i]);
        graph[v[i]].push(-u[i]);
    }
    
    vb vst(n+1,false);
    dfs(graph,vst,1);br;
    // print(graph,n);br;
}

int main(){
    freopen("input.txt","r",stdin);
    int t{1};
    // scanf("%d",&t);
    while(t--) solve();
}