#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<stack>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;

void Solve()
{
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        string t = s.substr(l - 1, r - l + 1);
        int len = t.length();
        cout<<t<<endl;
    }
    
}

int main()
{
    ios 
    int t = 1;
    //cin >> t;
    while(t--){
        Solve();
    }
    
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
const int mxn=1e5+10;
int n,q,a[mxn],sum[mxn][3];
char s[mxn];
int query(int l,int r,int x,int y,int z){
	return x-(sum[l+x-1][0]-sum[l-1][0])+y-(sum[l+x+y-1][1]-sum[l+x-1][1])+z-(sum[r][2]-sum[l+x+y-1][2]);
}
int main(){
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='r')a[i]=0;
		else if(s[i]=='e')a[i]=1;
		else a[i]=2;
	for(int i=1;i<=n;i++){
		sum[i][0]=sum[i-1][0];
		sum[i][1]=sum[i-1][1];
		sum[i][2]=sum[i-1][2];
		sum[i][a[i]]++;
	}
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		int len=r-l+1,p=len/3;
		if(len<3){
			puts("0");
			continue;
		}
		if(len%3==0)printf("%d\n",query(l,r,p,p,p));
		else if(len%3==1)printf("%d\n",min(query(l,r,p+1,p,p),min(query(l,r,p,p+1,p),query(l,r,p,p,p+1))));
		else printf("%d\n",min(query(l,r,p+1,p+1,p),min(query(l,r,p,p+1,p+1),query(l,r,p+1,p,p+1))));
	}
	return 0;
}
*/