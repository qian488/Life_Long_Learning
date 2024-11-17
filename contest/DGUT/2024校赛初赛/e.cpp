#include<bits/stdc++.h>

using namespace std;
typedef long long ll; 
#define endl "\n" 

bool check(string t){
   string s = t;
   reverse(s.begin(),s.end());
   return s==t;
}
 
void Solve(){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	vector<string> ans;
    int len = k;
	for(int i=0;i + len <= n;i++){
		string t = s.substr(i,len);
		if(check(t)) ans.push_back(t);
	}
    len++;
	for(int i=0;i + len <= n;i++){
		string t = s.substr(i,len);
		if(check(t)) ans.push_back(t);
	}
	sort(ans.begin(),ans.end());
    // for(auto e:ans) cout<<e<<endl;
	if(ans.size()==0){
		cout<<-1<<endl;
	}else{
		cout<<ans[0]<<endl;
	}
}

 
int main(){
	int t=1;
	// cin>>t;
	while(t--){
		Solve();
	}
	return 0;
}