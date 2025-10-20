#include<bits/extc++.h>
using namespace std;
vector<int> solve(vector<int> arr) {
    // Change the given code
    int n = arr.size();
    bool flag;
    for(int i=0;i<n-1;i++){
        flag = true;
        for(int j=0;j<n-1-i;j++) if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
            flag = false;
        }
        if(flag) break;
    }
    return arr;
}