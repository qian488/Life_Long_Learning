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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 1; i < n ; i++) cin >> a[i];
    vector<ll> ans(n);
    ans[0] = a[1] + 1e5;
    for (int i = 1; i < n ; i++){
        ans[i] = ans[i - 1] + a[i];
    }
    /*
    //逆向思维，去减
    ll kk = 1e9;
    vector<ll> ans;
    ans.push_back(kk);
    for (int i = n-2; i >= 0;i--){
        kk -= a[i];
        ans.push_back(kk);
    }
    reverse(ans.begin(), ans.end());
    */
    for (int i = 0; i < n;i++)
    {
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
    
    //Codeforces Round 943 (Div. 3)_C	Assembly via Remainders
    return 0;
}