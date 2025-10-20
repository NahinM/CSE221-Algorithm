#include <iostream>
#include <vector>
using namespace std;
#define br cout << '\n'

void bubbleSort(vector<long long> &arr){
	bool sorted = true;
	for(int i=0;i<arr.size()-1;i++){
    	sorted = true;
    	for(int j=0;j<arr.size()-1-i;j++){
        	if(arr[j]>arr[j+1]) {
            	swap(arr[j],arr[j+1]);
            	sorted = false;
        	}
    	}
    	if(sorted) return;
	}
}                                              	 
    
void solve(){
	int n;
	cin >> n;
	vector<long long> arr(n);
	for(int i=0;i<n;i++) cin >> arr[i];
	bubbleSort(arr);
	for(int i=0;i<n;i++) cout << arr[i] << ' ' ;br;
}
  
int main(){
	freopen("input.txt","r",stdin);
	solve();
}
