#include <iostream>
using namespace std;
#define br cout << '\n';

void solve(){
	long long n;
	cin >> n;
	cout << (((n+1)*n)>>1);br;
}

int main(){
	int t=1;
	cin >> t;
	while(t--) solve();
}
