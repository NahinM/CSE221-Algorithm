#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define br cout << '\n'
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int,int>
#define Edg tuple<int,int,int>
#define rept(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define exit {cout << "-1\n";return;}

class djSet{
    private:
        int N=0;
        vi set;
        vi rank;
    public:
        djSet(int n);
        void print();
        int parent(int x);
        bool frend(int a, int b);
    };
    
    djSet::djSet(int n){
        N = n;
        set.resize(N+1);
        rank.resize(N+1);
        rept(i,0,N+1){
            set[i] = i;
            rank[i] = 1;
        }
    }
    
    void djSet::print(){
        rept(i,0,N+1) cout << set[i] << ' ';br;
        rept(i,0,N+1) cout << rank[i] << ' ';br;br;
    }
    
    int djSet::parent(int x){
        if(set[x]==x) return x;
        int p = parent(set[x]);
        set[x] = p;
        return p;
    }
    
    bool djSet::frend(int a, int b){
        int pa = parent(a), pb = parent(b);
        if(pa==pb) return false;
        if(rank[pa]>rank[pb]){
            set[pb] = pa;
            rank[pa]+=rank[pb];
            rank[pb] = 0;
            return true;
        }
        set[pa] = pb;
        rank[pb]+=rank[pa];
        rank[pa] = 0;
        return true;
    }

void getEdges(vector<Edg> &edgs, int m){
    int u,v,w;
    priority_queue<pair<int,pii>> pq;
    while(m--) {
        cin >> u >> v >> w;
        pq.push({-w,{u,v}});
    }
    while(!pq.empty()){
        auto [ww,p] = pq.top(); pq.pop();
        auto &[uu,vv] = p;
        edgs.push_back({uu,vv,-ww});
    }
}

ll mst(vector<Edg> &edgs,vi &tree, vi &ecld, int n){
    djSet frnd(n);
    ll cost = 0, total = 0, i=-1;
    for(auto &[u,v,w]: edgs){ ++i;
        // cout << i << ',' << u << ',' << v << ',' << w << '\n';
        if(!frnd.frend(u,v)) {ecld.push_back(i) ;continue;}
        cost += w;
        ++total;
        tree.push_back(i);
    }
    if(total==n-1) return cost;
    return -1;
}

ll secMst(vector<Edg> &edgs, vi &tree,vi &ecld, int n, int nth){
    djSet frnd(n);
    ll cost = 0, total = 0;
    int ww = get<2>(edgs[nth]);

    for(int x:tree){
        if(x==nth) continue;
        auto &[u,v,w] = edgs[x];
        frnd.frend(u,v);
        ++total;
        cost += w;
    }
    
    for(int i:ecld){
        auto &[u,v,w] = edgs[i];
        // cout << i << ',' << u << ',' << v << ',' << w << '\n';
        if(w==ww) continue;
        if(!frnd.frend(u,v)) continue;
        cost += w;
        ++total;
        if(total==n-1) return cost;
    }
    return -1;
}

void solve(){
    int n,m;
    cin >> n >> m;
    vi tree,ecld;
    vector<Edg> edgs; getEdges(edgs,m);
    ll minCost = mst(edgs,tree,ecld,n);
    // cout << minCost << "\n";
    
    if(minCost==-1) exit
    priority_queue<ll> pq;
    for(int i:tree){
        ll cost = secMst(edgs,tree,ecld,n,i);
        // cout << cost << '\n';
        if(cost>minCost) pq.push(-cost);
    }
    cout << (pq.empty()?-1:-pq.top()) << '\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("input.txt","r",stdin);
    int t{1};
    cin >> t;
    while(t--) solve();
}