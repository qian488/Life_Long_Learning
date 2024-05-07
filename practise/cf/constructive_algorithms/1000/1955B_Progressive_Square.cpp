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
    int n,c,d;
    cin >> n >> c >> d;
    vector<int> a(n * n), b(n * n);
    for (int i = 0; i < n * n;i++) cin >> a[i];
    sort(a.begin(), a.end());
    b[0] = a[0];
    for (int i = 1; i < n;i++) b[i] = b[i - 1] + c;
    for (int i = 1; i < n;i++){
        for (int j = 0; j < n;j++){
            b[i * n + j] = b[(i - 1) * n + j] + d;
        }
    }
    sort(b.begin(), b.end());
    cout << ((a == b) ? "YES" : "NO") << endl;
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