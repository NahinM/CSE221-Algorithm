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
    int u,v,w;
    while (m--){
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
}

void danger(vpii *graph, int n){
    vi dng(n+1,__INT_MAX__); dng[1] = 0;
    priority_queue<pii> pq; pq.push({0,1});

    while(!pq.empty()){
        auto [d,at] = pq.top(); pq.pop();
        d = -d;
        if(dng[at]<d) continue;
        for(auto &[u,w]:graph[at]){
            int ddng = max(d,w);
            if(dng[u]>ddng){
                dng[u]=ddng;
                pq.push({-ddng,u});
            }
        }
    }

    rept(i,1,n+1) cout << (dng[i]==__INT_MAX__?-1:dng[i]) << ' ';br;
}

void solve(){
    int n,m;
    cin >> n >> m;
    vpii graph[n+1]; mkGraph(graph,m);
    danger(graph,n);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("input.txt","r",stdin);
    int t{1};
    cin >> t;
    while(t--) solve();
}