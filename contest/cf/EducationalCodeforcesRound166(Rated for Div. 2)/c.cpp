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
    ll ans[N];
    int n, m;
    cin >> n >> m;
    int len = n + m + 1;
    vector<ll> a(len), b(len);
    for (int i = 0; i < len;i++) cin >> a[i];
    for (int i = 0; i < len;i++) cin >> b[i];
    vector<pair<pll, ll>> v1, v2;
    for (int i = 0; i < len;i++){
        if(a[i]>b[i]){
            v1.push_back({{a[i], b[i]}, i});
        }else{
            v2.push_back({{b[i], a[i]}, i});
        }
    }
    if(v1.size()<=n){
        swap(n, m);
        swap(v1, v2);
    }
    while (v1.size()>n+1){ // 一共n+m+1,n个,m个,保留一个，假定是n+1个
        v2.push_back({{v1.back().first.second, v1.back().first.first}, v1.back().second});
        v1.pop_back();
    }
    ll sum = 0;
    for(auto e:v1) sum += e.first.first;
    for(auto e:v2) sum += e.first.first;
    for(auto e:v1) ans[e.second] = sum - e.first.first; // v1中是确定能够分配到的，v2中是只能去另外一个的
    for(auto e:v2) ans[e.second] = sum - e.first.first - v1.back().first.first + v1.back().first.second;
    for (int i = 0; i < len;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
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
