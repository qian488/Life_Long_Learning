#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
const int N=1e6+10;
int a[N],s[N];
//蓝桥真题_二进制商城
int qmi(int m,int k,int p)
{
	int res=1,t=m;
	while(k)
	{
		if(k&1) res=res*t%p;
		t=t*t%p;
		k>>=1;
	}
	return res;
}

void Solve(void)
{
	ll n,k;
	cin>>n>>k;
	ll ans=0;
	for(int i=0;i<k;i++)
	{
		ans+=qmi(2,i,MOD);
		if(ans>=n) break;
	}
	ans=min(n,ans);
	cout<<ans+1<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		Solve();
	}
	return 0;
}