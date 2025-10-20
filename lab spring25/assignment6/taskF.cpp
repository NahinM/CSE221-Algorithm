#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define rept(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
#define vb vector<bool>
#define br cout << '\n'

bool subStr(string &p, string &s){
    if(p.length()<s.length()) return false;
    rept(i,0,min(p.length(),s.length())){
        if(p[i]!=s[i]) return false;
    } return true;
}

void bfs(vi *graph, vi &deg, int total){
    priority_queue<int> pq; //cout << "deg: ";
    rept(i,0,26) {
        // cout << (char)('a'+i) << ':' << deg[i] << ' ';
        if(deg[i]==0) pq.push(-i);
    }
    string res = "";
    while (!pq.empty()){
        int at = -pq.top(); pq.pop();
        total--;
        res += (char)(at+'a');
        for(int u:graph[at]){
            deg[u]--;
            if(deg[u]==0) pq.push(-u);
        }
    }
    cout <<(total==0?res:"-1");br;
}

void solve(){
    int n;
    cin >> n;
    string p,s;
    cin >> p;
    vi graph[26]; vi deg(26,-1);
    int total = 0;
    while(--n){
        cin >> s;
        // cout << "pair: {" << p << ',' << s << "}\n";
        if(subStr(p,s)) {
            cout << "-1\n";
            return;
        }
        int u,v; bool falg = true;
        rept(i,0,max(p.length(),s.length())){
            if(i<p.length()){
                u=p[i]-'a';
                if(deg[u]==-1) {deg[u] = 0;total++;}
            }
            if(i<s.length()){
                v=s[i]-'a';
                if(deg[v]==-1) {deg[v] = 0;total++;}
            }
            if(falg && i<min(s.length(),p.length()) && s[i]!=p[i]){
                falg = false;
                graph[u].push_back(v);
                // cout << p[i] << " -> " << s[i];br;
                deg[v]++;
            }
        }
        p=s;
    }
    bfs(graph,deg,total);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("input.txt","r",stdin);
    int t{1};
    // cin >> t;
    while (t--) solve();
}
