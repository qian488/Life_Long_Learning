#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=1e5+10;
//蓝桥杯——接龙数列
//类似最长上升子序列
//贪心orDP? 
int dp[10];
int main()
{
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		int a=s[0]-'0';
		int b=s.back()-'0';
		dp[b]=max(dp[b],dp[a]+1);
		ans=max(ans,dp[b]);
	}
    ans=n-ans;
	cout<<ans<<endl;
	return 0;
}