#include <iostream>
#include <vector>
using namespace std;
#define br cout << '\n'
#define read(arr) for(auto &x:arr) cin >> x                       	 

int swaps = 0;

void sorting(vector<int> &id, vector<int> &mark){
    int n = id.size();
    for(int i=0;i<n-1; i++){
        int mx=i;
        for(int j=i+1; j<n; j++){
            if(mark[j]>mark[mx]) mx = j;
            if(mark[j]==mark[mx] && id[j]<id[mx]) mx = j; 
        }
        if(mx!=i) {
            swap(mark[i],mark[mx]);
            swap(id[i],id[mx]);
            swaps++;
        }
    }
}

void solve(){
	int n;
	cin >> n;
	vector<int> id(n),mark(n);
	read(id);
	read(mark);
	sorting(id,mark);
	cout << "Minimum swaps: " << swaps;br;
	for(int i=0;i<n;i++){
    	printf("ID: %d Mark: %d\n",id[i],mark[i]);
	}
}

int main(){
	freopen("input.txt","r",stdin);
	int t=1;
	// cin >> t;
	while(t--) solve();
}
