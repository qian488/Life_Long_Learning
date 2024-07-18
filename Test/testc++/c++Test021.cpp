#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 0x3f3f3f3f
typedef pair<int,int> PII;

#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)

vector<int> tems,anss,as;
bool check(int *a,int n,int mid,int k){
	int ans = 0;
	int now = 0;
	
	for(int i = 0;i<n;i++){
		int tem = a[i];
		tems.push_back(tem);
		as.push_back(a[i] - tem);
		while(i<n&&a[i]-tem<=mid){
			i++;
		}
		i--;
		ans++;
		anss.push_back(ans);
	}

	return ans<=k;
}
void solve()
{   
	int n,k;
	cin>>n>>k;
	int a[n];
	rep(i,0,n-1)cin>>a[i];
	sort(a,a+n);

	int l = 0,r = a[n-1]-a[0];
	vector<int> mids;

	while(l<r){
		int mid = l+r>>1;
		mids.push_back(mid);

		if(check(a,n,mid,k))r=mid;
		else l=mid+1;
	}
	cout << "mid:";
	for (vector<int>::iterator it = mids.begin(); it != mids.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "tem:";
	for (vector<int>::iterator it = tems.begin(); it != tems.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "ans:";
	for (vector<int>::iterator it = anss.begin(); it != anss.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "as:";
	for (vector<int>::iterator it = as.begin(); it != as.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout<<l;
	
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
//    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}