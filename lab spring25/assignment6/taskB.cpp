#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define rept(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
#define vb vector<bool>
#define br cout << '\n'

void makeGraph(vi *graph, int m){
    int u,v;
    while(m--){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

int bfs(vi *graph, vi &colr, int s){
    colr[s] = 1;
    int hum=1,rob=0;
    queue<int> Q; Q.push(s);
    int clr = 1;
    while(!Q.empty()){
        int at = Q.front(); Q.pop();
        for(int u:graph[at]) if(colr[u]==-1){
            colr[u] = 1-colr[at];
            colr[u]==1?hum++:rob++;
            Q.push(u);
        }
    }
    return max(hum,rob);
}

void solve(){
    int n,m;
    cin >> n >> m;
    vi graph[n+1];
    makeGraph(graph,m);
    vi colr(n+1,-1);
    int total = 0;
    rept(i,1,n+1) if(colr[i]==-1){
        total+=bfs(graph,colr,i);
    }
    cout << total;br;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("input.txt","r",stdin);
    int t{1};
    cin >> t;
    while (t--) solve();
}