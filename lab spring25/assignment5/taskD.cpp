#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define rept(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define vb vector<bool>
#define pqi priority_queue<int>
#define br cout << '\n'

void makeGraph(vi *graph,int n, int m){
    pqi g[n+1];
    int u,v;
    rept(i,m){
        cin >> u >> v;
        g[u].push(-v);
    }
    for(int i=1;i<=n; i++){
        pqi &gg = g[i];
        while (!gg.empty()){
            graph[i].push_back(-gg.top());
            gg.pop();
        }
    }
}

void printG(vi *g, int n){
    for(int i=1; i<=n; i++){
        cout << i << ": ";
        for(int u:g[i]) cout << "-> " << u;
        br;
    }br;
}

void bfs(vi *graph,vi &pr, int n, int s, int d){
    if(s==d) return;
    vb vst(n+1,false); vst[s] = true;
    queue<int> Q; Q.push(s);

    while (!Q.empty())
    {
        int at = Q.front(); Q.pop();
        // cout << at << ' ';
        if(at==d) return;
        for(int u:graph[at]) if(!vst[u]) {
            vst[u] = true;
            Q.push(u);
            pr[u] = at;
            if(u==d) return;
        }
    }
}

void path(const vi &pr,stack<int> &pth, int at, int to){
    while (at!=to && at!=0){
        pth.push(at);
        at = pr[at];
    }
}

void solve(){
    int n,m,s,d,k;
    cin >> n >> m >> s >> d >> k;
    vi graph[n+1];
    makeGraph(graph,n,m);
    // printG(graph,n);
    
    if(s==k && k==d){
        cout << "0\n" << s << '\n';
        return;
    }
    vi pr(n+1);
    stack<int> pth;
    if(k!=d){
        bfs(graph,pr,n,k,d);
        if(pr[d]==0){
            cout << "-1\n";
            return;
        }
        path(pr,pth,d,k);
    }
    rept(i,n+1) pr[i]=0;
    
    if(s!=k){
        bfs(graph,pr,n,s,k);
        if(pr[k]==0){
            cout << "-1\n";
            return;
        }
        path(pr,pth,k, s);
    }

    pth.push(s);
    cout << pth.size()-1 << '\n';
    while(!pth.empty()) {
        cout << pth.top() << ' ';
        pth.pop();
    }br;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("input.txt","r",stdin);
    int t{1};
    cin >> t;
    while(t--) solve();
}