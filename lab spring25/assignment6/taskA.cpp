#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

#define vi vector<int>
#define vb vector<bool>
#define br printf("\n")
#define rept(i,a,b) for(int i=a; i<b; i++)

void makeGraph(vi *graph,vi &deg, int m){
    int u,v;
    while(m--){
        scanf("%d %d",&u, &v);
        graph[u].push_back(v);
        deg[v]++;
    }
}

void topsort(vi *graph, vi &deg, int n){
    queue<int> pth;
    stack<int> stk;
    rept(i,1,n+1) if(deg[i]==0) stk.push(i);

    while (!stk.empty()){
        int at = stk.top(); stk.pop();
        pth.push(at);
        for(int u:graph[at]) {
            if(deg[u]>0) deg[u]--;
            if(deg[u]==0) stk.push(u);
        }
    }

    bool flg = false;
    for(int i=1; i<n+1; i++) if(deg[i]>0) {
        flg=true;
        break;
    }
    if(flg){
        printf("-1\n");
        return;
    }
    while (!pth.empty()){
        printf("%d ",pth.front()); pth.pop();
    }br;
}

void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    vi graph[n+1], deg(n+1);
    makeGraph(graph,deg,m);
    topsort(graph,deg,n);
}

int main(){
    freopen("input.txt","r",stdin);
    int t{1};
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}