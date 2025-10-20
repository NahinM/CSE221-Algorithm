#include <iostream>
using namespace std;
#define br cout << '\n';

void solve(){
	int n,k;
	cin >> n >> k;
	int arr[n];
	for(int i=0;i<n;i++) cin >> arr[i];
	for(int i=0;i<k;i++) cout << arr[k-i-1] << ' ';br;
}

int main(){
	freopen("input.txt","r",stdin);
	solve();
}
