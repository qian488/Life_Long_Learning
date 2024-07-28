#include<bits/stdc++.h>

typedef long long ll;
#define endl "\n"

using namespace std;

void Solve(void){
	int n;
	cin>>n;
	int ans=n/4;
	if(n%4==2) ans+=1;
	cout<<ans<<endl;
}

int main(){
	int t=1;
	cin>>t;
	while(t--){
		Solve();
	}
	return 0;
}
