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
#define MOD 100000000
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;

void Solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n + 1, 0);
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= m;i++){
        int x;
        cin >> x;
        if(x==1||x==n){
            cout << -1 << endl;
            return;
        }
        a[i] = x;
        vis[x] = true;
    }
    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n;i++){
        ans[i] = i;
    }
    for (int i = 1; i <= n; i++){
        if (vis[i]){
            swap(ans[i], ans[i + 1]);
        }
    }
    for (int i = 1; i <= n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    /*
    sort(a.begin(), a.end());
    vector<int> ans;
    a.push_back(0);
    vis[1] = true;
    ans.push_back(1);
    int tt = 2;
    for (int i = 0; i < m;i++){
        vis[a[i] + 1] = true;
        ans.push_back(a[i] + 1);
        if(a[i]!=a[i+1]-1){
            vis[tt] = true;
            ans.push_back(tt);
        }
    }
    for (int i = 1; i <= n;i++){
        if(!vis[i]) ans.push_back(i);
    }
    for(auto e:ans){
        cout << e << " ";
    }
    cout << endl;
    */
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
