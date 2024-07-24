#include<bits/stdc++.h>
typedef long long ll;
#define endl "\n"
using namespace std;

void Solve(void){
	int n,k;
	cin>>n>>k;
	int ans=0;
	int kk=n;
	for(int i=1;k>0;i++){
		k-=kk;
		ans++;
		if(i%2)kk--;
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
