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

void makeGraph(pqi *graph, int m){
    vi u(m),v(m);
    rept(i,m) cin >> u[i];
    rept(i,m) cin >> v[i];
    rept(i,m) {
        graph[u[i]].push(-v[i]);
        graph[v[i]].push(-u[i]);
    }
}

void bfs(pqi *graph,vi &prent,int n, int s, int d){
    vb vst(n+1,false); vst[s] = true;
    queue<int> Q; Q.push(s);

    while (!Q.empty())
    {
        int at = Q.front(); Q.pop();
        pqi &g = graph[at];

        while(!g.empty()) {
           int u = -g.top(); g.pop();
            if(!vst[u]){
                vst[u] = true;
                Q.push(u);
                prent[u] = at;
            }
        }
    }
}

void path(vi &prent,int at){
    stack<int> pth;
    int dpth = -1;
    while (at!=prent[at]){
        pth.push(at);
        dpth+=(at!=0);
        at = prent[at];
    }
    cout << dpth << '\n';

    while (!pth.empty()){
        cout << pth.top() << ' ';
        pth.pop();
    }
    br;
}

void solve(){
    int n,m,s,d;
    cin >> n >> m >> s >> d;
    pqi graph[n+1];
    makeGraph(graph,m);
    vi prent(n+1);
    if(s==d){
        cout <<"0\n"<< s << '\n';
        return;
    }
    bfs(graph,prent,n,s,d);
    if(prent[d]==0){
        cout << "-1\n";
        return;
    }
    path(prent,d);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("input.txt","r",stdin);
    int t{1};
    cin >> t;
    while(t--) solve();
}