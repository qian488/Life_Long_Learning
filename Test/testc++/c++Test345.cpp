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
    ll n, k, pb, ps;
    cin >> n >> k >> pb >> ps;
    vector<ll> p(n + 1), a(n + 1);
    for (int i = 1; i <= n;i++) cin >> p[i];
    for (int i = 1; i <= n;i++) cin >> a[i];
    ll Bs = 0, Ss = 0;
    ll tt = 0, kk = 0;
    for (int i = 1; i <= min(n, k);i++){
        if(a[pb]>tt) tt = a[pb];
        kk += a[pb];
        Bs = max(Bs, kk + (k - i) * tt);
        pb = p[pb];
    }
    tt = 0, kk = 0;
    for (int i = 1; i <= min(n, k);i++){
        if(a[ps]>tt) tt = a[ps];
        kk += a[ps];
        Ss = max(Ss, kk + (k - i) * tt);
        ps = p[ps];
    }
    if (Bs>Ss){
        cout << "Bodya" << endl;
    }
    else if(Bs<Ss){
        cout << "Sasha" << endl;
    }else{
        cout << "Draw" << endl;
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
    
    //Codeforces Round 943 (Div. 3)_D	Permutation Game
    return 0;
}