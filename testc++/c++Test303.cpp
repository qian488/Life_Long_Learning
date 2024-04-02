//滑窗

/*
//二分
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=1e6+10;

void Solve(void)
{
  int n;
  cin>>n;
  string s;
  char a,b;
  cin>>s>>a>>b;
  ll ans=0;
  vector<int> pca;
  for(int i=0;i<s.length();i++)
  {
  	if(s[i]==a) pca.push_back(i);
  	if(s[i]==b){
  		if(i-n+1<0||!pca.size()) continue;
  		
  		int l=0,r=pca.size()-1;
  		while(l<r)
  		{
  			int mid=l+r+1>>1;
  			if(pca[mid]<=(i-n+1))
  			{
  				l=mid;
			}
			else{
				r=mid-1;
			}
		}
		
		if(pca[l]<=(i-n+1)) ans+=(l+1);
	  }
  }
  cout<<ans<<endl;
}

int main()
{
  // 请在此输入您的代码
  int t=1;
  //cin>>t;
  while(t--)
  {
    Solve();
  }
  return 0;
}
*/