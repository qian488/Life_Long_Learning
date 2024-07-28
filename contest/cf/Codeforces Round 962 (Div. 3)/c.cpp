#include <bits/stdc++.h>
typedef long long ll;
#define endl "\n"
using namespace std;

void Solve(void){
	int n,q;
	cin>>n>>q;
	string a,b;
	cin>>a>>b;
	vector<vector<int>> pa(n+1,vector<int>(26,0));
	vector<vector<int>> pb(n+1,vector<int>(26,0));

	for(int i=0;i<n;i++){
		for(int c=0;c<26;c++){
			pa[i+1][c]=pa[i][c];
			pb[i+1][c]=pb[i][c];
		}
		pa[i+1][a[i]-'a']++;
		pb[i+1][b[i]-'a']++;
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		// l--,r--;
		vector<int> A(26,0),B(26,0);
		for(int i=0;i<26;i++){
			A[i]=pa[r][i]-pa[l-1][i];
			B[i]=pb[r][i]-pb[l-1][i];
		}
		
		int kk=0;
		for(int i=0;i<26;i++){
		kk+=abs(A[i]-B[i]);
		}
		cout<<kk/2<<endl;	
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
