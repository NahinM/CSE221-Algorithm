#include <iostream>
using namespace std;

void solve(){
    int n;
    cin >> n;
    cout << n << " is an " << (n&1?"Odd":"Even") << " number.\n";
}

int main(){
    int t=1;
    cin >> t;
    while(t--) solve();
}
