#include<bits/stdc++.h>
typedef long long ll;
#define endl "\n"
using namespace std;

void Solve(void){
	int n,k;
	cin>>n>>k;
	vector<string> g(n);
	for(int i=0;i<n;i++) cin>>g[i];
	int tt=n/k;
	for(int i=0;i<n;i+=k){
		for(int j=0;j<n;j+=k){
			cout<<g[i][j];
		}
		cout<<endl;
	}
}

int main(){
	int t=1;
	cin>>t;
	while(t--){
		Solve();
	}
	return 0;
}
