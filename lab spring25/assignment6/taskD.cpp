#include <iostream>
#include <vector>
using namespace std;

#define rept(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
#define vb vector<bool>
#define br cout << '\n'

int getSize(vi *graph,vb &vst, vi &sz, int root){
    if(sz[root] != 0) return sz[root];
    if(vst[root]) return 0;
    vst[root] = true;
    int r = 1;
    for(int u:graph[root]) if(!vst[u]){
        r+=getSize(graph,vst,sz,u);
    }
    sz[root] = r;
    return r;
}

void solve(){
    int n,R,u,v;
    cin >> n >> R;
    
    vi graph[n+1];
    rept(i,0,n-1) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vi sz(n+1);
    vb vst(n+1,false);
    int q,x;
    cin >> q;
    getSize(graph,vst,sz,R);

    while (q--)
    {
        cin >> x;
        cout << getSize(graph,vst,sz,x);br;
    }
    
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("input.txt","r",stdin);
    int t{1};
    // cin >> t;
    while (t--) solve();
}