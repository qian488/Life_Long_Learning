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
    int n,k;
    cin>>n>>k;
    k--;
    vector<pii> s(n);
    for(int i=0;i<n;i++) cin>>s[i].first;
    for(int i=0;i<n;i++) cin>>s[i].second;

    sort(s.begin(),s.end());

    ll ans, bsum=0;  
    priority_queue<int,vector<int>> q;
    
    for (int i = 0; i < n; i++) {
        int a = s[i].first;
        int b = s[i].second;

        q.push(b); 
        bsum += b;

        if(i < k) continue;

        if(i == k){
            ans = a * bsum;
        }else{
            bsum -= q.top(); 
            q.pop();
            ans = min(ans, a * bsum);
        }
    }

    cout << ans << endl;
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
