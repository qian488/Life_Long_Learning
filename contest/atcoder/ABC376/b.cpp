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
#include<bitset>
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
    cin>>n>>q;

    vector<pair<char,int>> a;
    for(int i=0;i<q;i++){
        char h;
        int t;
        cin>>h>>t;
        a.push_back({h,t});
    }

    int l = 1,r = 2,ans = 0;
    for (int i = 0; i < q; i++) {
        char h = a[i].first; 
        int t = a[i].second;
        if(h=='L'){
			if((r-t)*(r-l)>0){
                ans+=abs(l-t);
            }
			else{ 
                ans+=n-abs(l-t);
            }
			l=t;
		}
		if(h=='R'){
			if((l-t)*(l-r)>0){
                ans+=abs(r-t);
            }
			else{ 
                ans+=n-abs(r-t);
            }
			r=t;
		}
    }
    cout<<ans<<endl;
}

int main()
{
    ios 
    int t = 1;
    // cin >> t;
    while(t--){
        Solve();
    }
    
    return 0;
}
