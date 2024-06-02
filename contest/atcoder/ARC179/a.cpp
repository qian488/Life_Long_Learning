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

int n, k;

bool check(vector<int>& a) {
    vector<int> b(n + 1, 0);

    for (int i = 0; i < n; i++) {
        b[i + 1] = b[i] + a[i];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (b[i] < k && b[j] >= k) {
                return false;
            }
        }
    }

    return true;
}

void Solve()
{
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (check(a)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
        return;
    }

    vector<int> ans;
    sort(a.begin(), a.end());

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum + a[i] < k) {
            ans.push_back(a[i]);
            sum += a[i];
        } else {
            break;
        }
    }

    for (int i = ans.size(); i < n; i++) {
        ans.push_back(a[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
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
