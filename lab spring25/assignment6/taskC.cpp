#include <iostream>
#include <queue>
using namespace std;

#define pii pair<int,int>
#define rept(i,a,b) for(int i=a; i<b; i++)
#define br cout << '\n'

int n;

bool valid(int x,int y){
    return 1<=x && x<=n && 1<=y && y<=n;
}

int check(int x1, int y1, int x2, int y2){
    int vst[n+1][n+1] = {};
    queue<pii> Q;

    Q.push({x1,y1});
    int dr[8] = {-2,-2,-1,1,2,2,1,-1};
    int dc[8] = {-1,1,2,2,1,-1,-2,-2};

    while (!Q.empty())
    {
        pii tem = Q.front();Q.pop();
        int x=tem.first, y=tem.second;
        // cout << x << " " << y;br;
        rept(i,0,8) {
            int xx = x+dr[i];
            int yy = y+dc[i];
            if(valid(xx,yy) && vst[xx][yy]==0){
                vst[xx][yy] = vst[x][y]+1;
                Q.push({xx,yy});
            }
            if(xx==x2 && yy==y2) return vst[xx][yy];
        }
    }
    return -1;    
}

void solve(){
    int x1,x2,y1,y2;
    cin >> n;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << check(x1,y1,x2,y2) << '\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("input.txt","r",stdin);
    int t{1};
    cin >> t;
    while (t--) solve();
}