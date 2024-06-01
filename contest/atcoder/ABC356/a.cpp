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
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> v, a, b;
    for (int i = l; i <= r;i++){
        v.push_back(i);
    }
    reverse(v.begin(), v.end());
    for (int i = 1; i < l;i++) a.push_back(i);
    for (int i = r + 1; i <= n; i++) b.push_back(i);
    for(auto e:a) cout << e << " ";
    for(auto e:v) cout << e << " ";
    for(auto e:b) cout << e << " ";
    cout << endl;
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
