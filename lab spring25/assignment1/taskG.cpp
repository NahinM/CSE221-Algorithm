#include <iostream>
#include <vector>
using namespace std;

struct  train
{
    string name;
    string dprt;
    int min;
    int sec;
};

string toTime(int min,int sec){
    string s;
    if(min<10) s+='0';
    s+= to_string(min);
    s+=':';
    if(sec<10) s+='0';
    s+= to_string(sec);
    return s;
}

void sorting(vector<train> &trn){
    int n = trn.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(trn[j].name>trn[j+1].name) swap(trn[j],trn[j+1]);
            else if(trn[j].name==trn[j+1].name 
                && trn[j].min*60+trn[j].sec<trn[j+1].min*60+trn[j+1].sec) swap(trn[j],trn[j+1]);
        }
    }
}

void solve(){
    string s;
    char c;
    int n;

    cin >> n;
    vector<train> trn(n);
    for(train &tt:trn){
        cin >> tt.name >> s >> s >> s >> tt.dprt >> s >> tt.min >> c >> tt.sec;
    }

    sorting(trn);
    for(train &tt:trn)
        cout << tt.name << " will departure for " << tt.dprt << " at " << toTime(tt.min,tt.sec) << '\n';
}

int main(){
    freopen("input.txt","r",stdin);
    int t=1;
    // cin >> t;
    while(t--) solve();
}
