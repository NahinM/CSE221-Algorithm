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
#define ll long long
#define vl vector<ll>
#define rept(i,a,b) for(int i=a;i<b;i++)

void mkGraph(vpii *graph, int m){
    int u,v,w;
    while (m--){
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
    }
}

void dijkstra(vpii *graph, vl &dst, int s){
    dst[s] = 0;
    priority_queue<pii> pq; pq.push({0,s});

    while(!pq.empty()){
        auto [d,at] = pq.top(); pq.pop();
        d = -d;
        for(auto &[u,w]:graph[at]){
            int cost = d+w;
            if(cost<dst[u]){
                dst[u] = cost;
                pq.push({-cost,u});
            }
        }
    }
}

void solve(){
    int n,m,s,t;
    cin >> n >> m >> s >> t;
    vpii graph[n+1]; mkGraph(graph,m);
    vl dst1(n+1,__INT_MAX__), dst2(n+1,__INT_MAX__);
    dijkstra(graph,dst1,s);
    dijkstra(graph,dst2,t);

    ll time = (ll)2147483647,node;
    rept(i,1,n+1){
        // cout << dst1[i] << ',' << dst2[i] << '\n';
        ll t = max(dst1[i],dst2[i]);
        if(time > t){
            time = t;
            node = i;
        }
    }
    if(time>=2147483647){
        cout << "-1\n";
        return;
    }
    cout << time << ' ' << node << '\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("input.txt","r",stdin);
    int t{1};
    cin >> t;
    while(t--) solve();
}