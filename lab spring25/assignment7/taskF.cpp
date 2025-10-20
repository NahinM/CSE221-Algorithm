#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define br cout << '\n'
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define pii pair<int,int>
#define vpii vector<pii>
#define rept(i,a,b) for(int i=a;i<b;i++)
#define INF 0x7fffffff

void mkGraph(vpii *graph, int m){
    int u,v,w;
    while (m--){
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
}

void dijkstra(vpii *graph, int n, int S, int D){
    vl dst1(n+1,__INT_MAX__), dst2(n+1,__INT_MAX__);
    dst1[S] = 0;
    priority_queue<pair<ll,int>> pq; pq.push({0,S});

    while(!pq.empty()){
        auto [d,at] = pq.top(); pq.pop();
        d = -d;
        // cout << d << ',' << at << '\n';
        for(auto &[u,w]:graph[at]){
            ll cost = w+d;
            if(cost < dst1[u]){
                dst2[u] = dst1[u];
                dst1[u] = cost;
                pq.push({-cost,u});
            }
            if(dst1[u] < cost && cost < dst2[u]){
                dst2[u] = cost;
                pq.push({-cost,u});
            }
        }
    }
    // cout << dst1[D] << '\n';
    if(dst2[D]>=__INT_MAX__){
        cout << "-1\n";
        return;
    }
    cout << dst2[D] << '\n';
}

void solve(){
    int n,m,s,d;
    cin >> n >> m >> s >> d;
    vpii graph[n+1]; mkGraph(graph,m);
    dijkstra(graph,n,s,d);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("input.txt","r",stdin);
    int t{1};
    cin >> t;
    while(t--) solve();
}