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
#define INF (ll)2e18
#define MOD 100000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;

void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
        
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool zero = true;
    for (int i = 0; i < n;i++){
        if (a[i] != 0) {
            zero = false;
            break;
        }
    }
    if (zero) {
        cout << 0 << endl;
        cout << endl;
        return;
    }

    vector<int> ans;
    for (int i = 0; i < 40; i++) {
        sort(a.begin(), a.end());
        int minn = a[0], maxn = a[n - 1];
        int x = (minn + maxn) / 2;
        ans.push_back(x);
        for (int k = 0; k < n;k++){
            a[k] = abs(a[k] - x);
        }
        zero = true;
        for (int i = 0; i < n;i++){
            if (a[i] != 0) {
                zero = false;
                break;
            }
        }
        if(zero) break;
    }

    if (!zero) {
        cout << -1 << endl;
    } else {
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size();i++){
            cout << ans[i] << " ";
        }
        cout << endl;
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
    
    return 0;
}
