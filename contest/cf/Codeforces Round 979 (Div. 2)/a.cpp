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
    cin>>n;
    vector<int> a(n),b(n),c(n);
    for (int i = 0; i < n; i++) cin>>a[i];
    sort(a.begin(), a.end()); 
    vector<int> aa;
    int i = 0, j = n - 1;
    while (i <= j) {
        if (j >= i) aa.push_back(a[j--]); 
        if (i <= j) aa.push_back(a[i++]); 
    }
/*
    for(auto e:aa) cout<<e<<" ";
    cout<<endl;
*/
    b[0] = aa[0];
    for (int i = 1; i < n; i++) b[i] = min(b[i - 1], aa[i]);

    c[0] = aa[0];
    for (int i = 1; i < n; i++) c[i] = max(c[i - 1], aa[i]);

    int ans = 0;
    for (int i = 0; i < n; i++) ans += (c[i] - b[i]);
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
