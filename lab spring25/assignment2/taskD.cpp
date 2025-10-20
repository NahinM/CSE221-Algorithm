#include <iostream>
using namespace std;

void solve(){
    string s;
    cin >> s;

    if(s[0]=='1') {
        cout << "1\n";
        return;
    }
    int n = s.length();
    if(s[n-1]=='0') {
        cout << "-1\n";
        return;
    }
    int lw=0,hi=n-1,mid,head=0;
    while (lw<=hi)
    {
        mid = (lw+hi)>>1;
        if(s[mid]!='1') lw = mid+1;
        else {
            head = mid;
            hi = mid-1;
        } 
    }
    cout << head+1 << '\n';
}

int main(){
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    cin >> t;
    while(t--) solve();
}