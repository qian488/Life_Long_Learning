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

ll n, m, k, c;
ll fa[N];
struct edge{
    ll u, v, w;
    bool operator<(const edge t)const{
        return w < t.w;
    }
};
vector<edge> a;

bool cmp(edge x,edge y){
    return x.w < y.w;
}
ll find(ll x){
    return x == fa[x] ? x : (fa[x] = find(fa[x]));
}
void merge(ll x,ll y){
    fa[find(x)] = find(y);
}
void init(){
    for(int i=1;i<=n;i++) fa[i] = i;
}

void Solve()
{
    cin >> n >> m;
    init();
    while(m--){
        cin >> k >> c;
        ll pos;
        cin >> pos;
        for (int i = 1; i < k; i++){
            ll x;
            cin>>x;
            a.push_back({pos, x, c});
        }
    }
    sort(a.begin(), a.end(), cmp);
    ll cnt = 0, ans = 0;
    for (ll i = 0; i < a.size(); i++){
        ll e1 = find(a[i].u);
        ll e2 = find(a[i].v);
        if(e1!=e2){
            fa[e1] = e2;
            ans += a[i].w;
            cnt++;
        }
        if(cnt==n-1) break;
    }
    if(cnt<n-1) cout<<-1;
    else cout<<ans;
}

int main()
{
    ios 
    int t = 1;
    //cin >> t;
    while(t--){
        Solve();
    }
    
    //AtCoder Beginner Contest 352_E	Clique Connect
    return 0;
}