#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define br cout << '\n'
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int,int>
#define vpii vector<pii>
#define rept(i,a,b) for(int i=a;i<b;i++)
#define INF 0x7fffffff

void mkgraph(vi *graph, int m){
    int u,v;
    while(m--){
        cin >> u >> v;
        graph[u].push_back(v);
    }
}

void djsktra(vi *graph, vi &w, int N, int S, int D){
    vi dst(N+1,INF); dst[S] = w[S];
    priority_queue<pii> pq; pq.push({-w[S],S});

    while(!pq.empty()){
        auto [c,at] = pq.top(); pq.pop();
        c=-c;
        if(at==D){cout << dst[D] << '\n';return;}
        if(dst[at]<c) continue;
        for(int u:graph[at]){ 
            int cst = c+w[u];
            if(cst<dst[u]){
                dst[u] = cst;
                pq.push({-cst,u});
            }
        }
    }
    cout << "-1\n";
}

void solve(){
    // input ->
    int n,m,s,d;
    cin >> n >> m >> s >> d;
    vi w(n+1); rept(i,1,n+1) cin >> w[i];
    vi graph[n+1]; mkgraph(graph,m);

    // solve -> 
    djsktra(graph,w,n,s,d);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("input.txt","r",stdin);
    int t{1};
    cin >> t;
    while(t--) solve();
}