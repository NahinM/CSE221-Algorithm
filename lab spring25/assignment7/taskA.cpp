#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
 
#define br cout << '\n'
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int,int>
#define vpii vector<pii>
#define rept(i,a,b) for(int i=a;i<b;i++)
 
void mkGraph(vpii *graph, int m){
    int u[m],v[m],w[m];
    rept(i,0,m) cin >> u[i];
    rept(i,0,m) cin >> v[i];
    rept(i,0,m) cin >> w[i];
    rept(i,0,m) graph[u[i]].push_back({v[i],w[i]});
}
 
void djkstra(vpii *graph, int n, int S, int D){
    priority_queue<pii> pq; pq.push({0,S});
    vb vst(n+1,false); vst[S] = true;
    vi dst(n+1,__INT_MAX__); dst[S] = 0;
    vi pre(n+1);
 
    while(!pq.empty()){
        auto [d,at] = pq.top(); pq.pop(); d=-d;
        vst[at] = true;
        if(d>dst[at]) continue;
        if(at==D) break;
        for(auto &[u,w]:graph[at]) if(!vst[u]){
            int dd = d+w;
            if(dd<dst[u]){
                dst[u] = dd;
                pre[u] = at;
                pq.push({-dd,u});
            }
            // rept(i,0,n+1) cout << dst[i] << ' ';br;
        }
    }
 
    // rept(i,0,n+1) cout << dst[i] << ' ';br;
    // rept(i,0,n+1) cout << pre[i] << ' ';br;
 
    if(dst[D]==__INT_MAX__){
        cout << "-1\n";
        return;
    }
    
    stack<int> pth;
    for(int at=D; at!=0; at = pre[at]) pth.push(at);
 
    cout << dst[D] << '\n';
    while (!pth.empty()) {
        cout << pth.top() << ' '; pth.pop();
    }br;
    
}
 
void solve(){
    int n,m,s,d;
    cin >> n >> m >> s >> d;
    vpii graph[n+1]; mkGraph(graph,m);
    djkstra(graph,n,s,d);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("input.txt","r",stdin);
    int t{1};
    cin >> t;
    while(t--) solve();
}