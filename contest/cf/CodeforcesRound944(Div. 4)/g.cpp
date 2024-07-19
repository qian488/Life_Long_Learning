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

vector<int> a(N), ans(N);

bool cmp(int i,int j){
    return a[i] < a[j];
}

void Solve()
{
    int n;
    cin >> n;
    map<int, vector<int>> mp;
    for (int i = 0; i < n;i++){
        cin >> a[i];
        mp[a[i] >> 2].push_back(i);
    }

    for(auto [x,v]:mp){
        vector<int> tt = v;
        sort(tt.begin(), tt.end(), cmp);
        for (int i = 0; i < tt.size();i++) ans[v[i]] = a[tt[i]];
    }

    for (int i = 0; i < n;i++) cout << ans[i] << " ";
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