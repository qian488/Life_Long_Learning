#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void Solve(void){
	ll n,m;
	cin>>n>>m;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	sort(v.begin(),v.end());
	int i=0,j=0;
	ll ans=0,cur=0;
	while(i<n){
		cur+=v[i];
		while(cur>m||(v[i]-v[j])>1&&j<n){
			cur-=v[j];
			j++;
		}
		ans=max(ans,cur);
		i++;
	}
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
