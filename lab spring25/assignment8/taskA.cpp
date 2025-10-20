#include <iostream>
#include <vector>
using namespace std;

#define br cout << '\n'
#define vi vector<int>
#define vb vector<bool>
#define rept(i,a,b) for(int i=a;i<b;i++)

class djSet{
private:
    int N=0;
    vi set;
    vi rank;
public:
    djSet(int n);
    void print();
    int parent(int x);
    int frend(int a, int b);
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

int djSet::frend(int a, int b){
    int pa = parent(a), pb = parent(b);
    if(pa==pb) return rank[pa];
    if(rank[pa]>rank[pb]){
        set[pb] = pa;
        rank[pa]+=rank[pb];
        rank[pb] = 0;
        return rank[pa];
    }
    set[pa] = pb;
    rank[pb]+=rank[pa];
    rank[pa] = 0;
    return rank[pb];
}


void solve(){
    int n,k;
    cin >> n >> k;
    djSet frnd(n);
    // frnd.print();
    int a,b;
    while(k--){
        cin >> a >> b;
        cout << frnd.frend(a,b) << '\n';
        // frnd.print();
    }
    // br;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("input.txt","r",stdin);
    int t{1};
    // cin >> t;
    while(t--) solve();
}