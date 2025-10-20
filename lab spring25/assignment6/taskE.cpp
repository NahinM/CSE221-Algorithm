#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define rept(i,a,b) for(int i=a;i<b;i++)
#define br cout << '\n'
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int,int>

void makeGraph(vi *graph,int m){
    int u,v;
    while(m--){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

pii bfs(vi *graph, int n, int s){
    vb vst(n+1,false); vst[s] = true;
    queue<pii> Q; Q.push({0,s});
    pii far = {0,s};

    while(!Q.empty()){
        pii tem = Q.front(); Q.pop();
        int d = tem.first, at = tem.second;
        for(int u:graph[at]) if(!vst[u]){
            vst[u] = true;
            Q.push({d+1,u});
            if(d+1>far.first){
                far = {d+1,u};
            }
        }
    }
    return far;
}

void solve(){
    int n;
    cin >> n;
    vi graph[n+1];
    makeGraph(graph,n-1);

    pii a = bfs(graph,n,1);
    int f = a.second;
    pii b = bfs(graph,n,f);
    cout << b.first << '\n' 
         << f << ' ' << b.second << '\n'; 
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("input.txt","r",stdin);
    int t{1};
    cin >> t;
    while (t--) solve();
}