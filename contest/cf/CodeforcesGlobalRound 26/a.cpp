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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (a[0] == a[n-1]) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        if (a[i] == a[0]) {
            cout << "B";
        } else if (a[i] == a[n-1]) {
            cout << "R";
        } else {
            cout << ((i % 2 == 0) ? "B" : "R");
        }
    }
    cout << endl;
    /*
    if (a[0] == a[n - 1]) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << string(n - 1, 'R') << "B" << endl;
    }
    */
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
