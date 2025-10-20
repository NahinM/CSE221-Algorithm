#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

#define rept(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define vb vector<bool>
#define qint queue<int>
#define br printf("\n")

void print(vector<vi> &graph,int n){
    for(int i=1;i<=n;i++){
        printf("%d: ",i);
        for(int u:graph[i]){
            printf(" -> %d",u);
        }br;
    }
}

void bfs(vector<vi> &graph, int n){
    vb vst(n+1,false); vst[1] = true;
    qint Q; Q.push(1);
    
    while (!Q.empty())
    {
        int at = Q.front();Q.pop();
        for(int u:graph[at]) if(!vst[u]){
            Q.push(u);
            vst[u] = true;
        }
        printf("%d ",at);
    }br;
}

void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<vi> graph(n+1);
    int u,v;
    rept(i,m){
        scanf("%d %d",&u,&v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    // print(graph,n);
    bfs(graph,n);
}

int main(){
    freopen("input.txt","r",stdin);
    int t{1};
    scanf("%d",&t);
    while(t--) solve();
}