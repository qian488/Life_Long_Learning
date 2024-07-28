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
    while (a.size() > 1) {
        int kk = INF;
        int min_index = -1;
        for (int i = 0; i < a.size() - 1; i++) {
            int sum = a[i] + a[i + 1];
            if (sum < kk) {
                kk = sum;
                min_index = i;
            }
        }
        a.erase(a.begin() + min_index, a.begin() + min_index + 2);
    }
    cout << a[0] << endl;
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
