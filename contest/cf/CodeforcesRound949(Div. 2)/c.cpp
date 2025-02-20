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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    if (count(a.begin(), a.end(), -1) == n) {
        for (int i = 0; i < n; i++) {
            a[i] = i % 2 + 1;
        }
    } else {
        for (int i = 0, j = -1; i <= n; i++) {
            if (i == n || a[i] != -1) {
                if (j == -1) {
                    for (int k = i - 1; k >= 0; k--) {
                        a[k] = a[k + 1] == 1 ? 2 : a[k + 1] / 2;
                    }
                } else if (i == n) {
                    for (int k = j + 1; k < n; k++) {
                        a[k] = a[k - 1] == 1 ? 2 : a[k - 1] / 2;
                    }
                } else {
                    int l = j, r = i;
                    while (l + 1 < r) {
                        if (a[l] > a[r]) {
                            a[l + 1] = a[l] == 1 ? 2 : a[l] / 2;
                            l++;
                        } else {
                            a[r - 1] = a[r] == 1 ? 2 : a[r] / 2;
                            r--;
                        }
                    }
                    if (a[l] != a[r] / 2 && a[r] != a[l] / 2) {
                        cout << -1 << "\n";
                        return;
                    }
                }
                j = i;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
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
