#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define br cout << '\n'
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int,int>
#define vpii vector<pii>
#define Edg tuple<int,int,int>
#define rept(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define exit {cout << "-1\n";return;}

void mkgraph(vpii *graph, int m){
    int u,v,w;
    while(m--){
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
}

ll prims(vpii *graph, vector<Edg> &picked, int n, int nth){
    vb vst(n+1,false);
    priority_queue<Edg> pq; pq.push({0,0,1});
    ll cost = 0, total = 0;
    int uu,vv,ww;

    if(nth != -1){
        uu = get<0>(picked[nth]);
        vv = get<1>(picked[nth]);
        // cout << uu << ',' << vv << ',' << ww << '\n';
    }


    while(!pq.empty()){
        auto [d,v,at] = pq.top(); pq.pop();
        d = -d;
        if(vst[at]) continue;
        vst[at] = true;
        cost+=d;
        total++;
        if(nth == -1) picked.push_back({v,at,d});

        for(auto &[u,w]:graph[at]) if(!vst[u]){
            if(at!=-1 &&
              ((uu==at && vv==u) ||
              (uu==u && vv==at))) continue;

            pq.push({-w,at,u});
        }
    }
    return total==n?cost:-1;
}

void solve(){
    int n,m;
    cin >> n >> m;
    vpii graph[n+1]; mkgraph(graph,m);
    vector<Edg> picked;
    ll minCost = prims(graph,picked,n,-1);
    if(minCost==-1) exit
    // cout << minCost << '\n';
    // for( auto [u,v,w]:picked) cout << u << ',' << v << ',' << w << '\n';
    ll secondCost = __LONG_LONG_MAX__;
    for(int i=1;i<picked.size(); i++){
        ll cost = prims(graph,picked,n,i);
        // cout << cost << '\n';
        if(minCost<cost && cost<secondCost) secondCost = cost;
    }
    if(secondCost==__LONG_LONG_MAX__) exit;
    cout << secondCost << '\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("input.txt","r",stdin);
    int t{1};
    cin >> t;
    while(t--) solve();
}