#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define rept(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
#define vb vector<bool>
#define pqi priority_queue<int>
#define br printf("\n")
#define yes printf("YES\n")
#define no printf("NO\n")

void makeGraph(pqi *graph, int m){
    int u,v;
    while(m--){
        scanf("%d %d",&u,&v);
        graph[u].push(v);
    }
}

bool cyclic = false;

void dfs(pqi *graph,vb &vst, int n, int s){
    vst[s] = true;
    stack<int> stk; stk.push(s);
    vb rec(n+1,false); rec[s] = true;

    while (!stk.empty()){
        int at{stk.top()};
        bool picked = false;
        pqi &g{graph[at]};

        while (!g.empty()){
            int u{g.top()}; g.pop();
            if(rec[u]) {
                cyclic = true;
                return;
            }
            if(!vst[u]){
                vst[u] = true;
                stk.push(u);
                picked = true;
                rec[u] = true;
                break;
            }
        }

        if(!picked){
            rec[stk.top()]=false;
            stk.pop();
        }
    }
}

void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    pqi graph[n+1];
    makeGraph(graph,m);
    cyclic = false;
    vb vst(n+1,false);
    for(int i=1; i<=n && !cyclic; i++) if(!vst[i]) dfs(graph,vst,n,i);
    cyclic?yes:no;
}

int main(){
    freopen("input.txt","r",stdin);
    int t{1};
    scanf("%d",&t);
    while(t--) solve();
}