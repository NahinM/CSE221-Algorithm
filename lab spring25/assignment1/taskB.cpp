#include <iostream>
using namespace std;

void solve(){
	string s;
	double a,b,ans;
	char optor;
	cin >> s >> a >> optor >> b;
	if(optor=='+') printf("%.6f\n",a+b);
	else if(optor=='-') printf("%.6f\n",a-b);
	else if(optor=='*') printf("%.6f\n",a*b);
	else if(optor=='/') printf("%.6f\n",a/b);
	
}

int main(){
    freopen("input.txt","r",stdin);
	int t=1;
	cin >> t;
	while(t--) solve();
}
