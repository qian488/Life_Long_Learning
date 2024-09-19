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
#define ios {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int N=2e5+10;

void Solve()
{
    int n,k,q;
    cin>>n>>k>>q;
    vector<int>a(n+1);
    vector<int>cnt(2*n+1,0);
    vector<int>ans(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=n-i;
    }
    int l=1,r=l+k-1;
    multiset<int>st;
    for(int i=l;i<=r;i++) cnt[a[i]]++;
    for(int i=0;i<=2*n;i++) st.insert(cnt[i]);
    ans[l]=*st.rbegin();
    while(r<n){
        st.erase(st.lower_bound(cnt[a[l]]));
        cnt[a[l]]--;
        st.insert(cnt[a[l]]);
        l++,r++;
        st.erase(st.lower_bound(cnt[a[r]]));
        cnt[a[r]]++;
        st.insert(cnt[a[r]]);
        ans[l]=*st.rbegin();
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<k-ans[l]<<endl;
    }
}

int main()
{
    ios 
    int t = 1;
    cin >> t;
    while(t--){
        Solve();
    }
    
    return 0;
}
