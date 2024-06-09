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
    int n;
    cin >> n;
    
    vector<int> a(n);
    bool tt = false;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i]>0) tt = true;
    }
    ll c = 0;
    if(!tt){
        for(auto e:a) c += e;
        cout << abs(c) << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        ll kk = abs(c + a[i]);
        c += a[i];
        c = max(kk, c);
    }

    cout << c << endl;
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
