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
    string s,r;
    cin>>s>>r;
    vector<bool> vis(n+1,false);


    for (int i = 0; i < n - 1; i++) {
        bool found = false;
        for (int k = 0,j=k+1; k < s.length() - 1; k++) {
            while(vis[j]) j++;
            if (s[k] != s[j]) {
                s[k] = r[i];
                vis[j] = true;
                found = true;
                break;
            }
        }
        
        if (!found) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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
