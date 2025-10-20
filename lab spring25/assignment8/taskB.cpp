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
#define ll long long

void mkgraph(vpii *graph, int m){
    int u,v,w;
    while(m--){
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
}

void primsAlgo(vpii *graph, int n){
    vb vst(n+1,false);
    priority_queue<pii> pq; pq.push({0,1});

    ll cost = 0;
    while(!pq.empty()){
        auto [w,at] = pq.top(); pq.pop();
        if(vst[at]) continue;
        w = -w;
        vst[at] = true;
        cost+=w;
        // cout << w << ',' << at << '\n';
        for(auto &[u,w]:graph[at]) if(!vst[u]){
            pq.push({-w,u});
        }
    }
    cout << cost << '\n';
}

void solve(){
    int n,m;
    cin >> n >> m;
    vpii graph[n+1]; mkgraph(graph,m);
    primsAlgo(graph,n);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("input.txt","r",stdin);
    int t{1};
    cin >> t;
    while(t--) solve();
}