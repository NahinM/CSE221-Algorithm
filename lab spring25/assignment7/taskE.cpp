#include <iostream>
#include <vector>
#include <tuple>
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

void mkgraph(vpii *graph, int m){
    int u[m],v[m],w[m];
    rept(i,0,m) cin >> u[i];
    rept(i,0,m) cin >> v[i];
    rept(i,0,m) cin >> w[i];
    rept(i,0,m) {
        // cout << u[i] << ' ' << v[i] << ' ' << w[i] << '\n';
        graph[u[i]].push_back({v[i],w[i]});
    }
}

ll dijkstra(vpii *graph, int N){
    vl dst1(N+1,__LONG_LONG_MAX__); dst1[1] = 0;
    vl dst2(N+1,__LONG_LONG_MAX__); dst2[1] = 0;
    priority_queue<tuple<ll,int,int>> pq;
    pq.push({0,1,0});
    pq.push({0,1,1});

    while(!pq.empty()){
        auto [d,at,p] = pq.top(); pq.pop();
        d=-d;
        // if(at == N) return d;
        for(auto &[u,w]:graph[at]) if((p%2)!=(w%2)){
            ll cost = d+w;
            if(p%2==0 &&  cost<dst1[u]){
                dst1[u] = cost;
                pq.push({-cost,u,w});
            }
            if(p%2==1 &&  cost<dst2[u]){
                dst2[u] = cost;
                pq.push({-cost,u,w});
            }
        }
    }
    ll ans = min(dst1[N],dst2[N]);
    return ans!=__LONG_LONG_MAX__?ans:-1;
}

void solve(){
    int n,m;
    cin >> n >> m;
    vpii graph[n+1]; mkgraph(graph,m);
    
    cout << dijkstra(graph,n) << '\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("input.txt","r",stdin);
    int t{1};
    cin >> t;
    while(t--) solve();
}