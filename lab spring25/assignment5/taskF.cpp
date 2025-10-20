#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define rept(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define vb vector<bool>
#define br cout << '\n'

int R,C,mx;

bool valid(int r, int c){
    return 0<=r && r<R && 0<=c && c<C;
}

void bfs(string grid[],vector<vb> &vst,int r, int c){
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,1,0,-1};
    queue<int> Qr,Qc; Qr.push(r); Qc.push(c);
    vst[r][c] = true;
    int total = grid[r][c]=='D';

    while (!Qr.empty()){
        int atr = Qr.front(), atc = Qc.front(); Qr.pop(); Qc.pop();
        rept(i,4){
            int rr = atr+dr[i], cc = atc+dc[i];
            if(valid(rr,cc) && grid[rr][cc]!='#' && !vst[rr][cc]){
                total+=(grid[rr][cc]=='D');
                Qr.push(rr); Qc.push(cc);
                vst[rr][cc] = true;
            }
        }
    }
    mx = max(total,mx);
}

void solve(){
    cin >> R >> C;
    string grid[R];
    rept(i,C) cin >> grid[i];

    mx = 0;
    vector<vb> vst(R,vb(C,false));
    rept(i,R) rept(j,C) if(!vst[i][j] && grid[i][j]!='#') bfs(grid,vst,i,j);
    // rept(i,R) {
    //     rept(j,C){
    //         cout << vst[i][j];
    //     }br;
    // }
    cout << mx;br;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("input.txt","r",stdin);
    int t{1};
    // cin >> t;
    while(t--) solve();
}