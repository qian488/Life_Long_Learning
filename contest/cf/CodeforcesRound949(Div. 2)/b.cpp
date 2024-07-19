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
    int n, m;
    cin >> n >> m;
    int ans = (n | n + 1 | n + 2);
    if(m==0) {
        ans = n;
        cout << ans << endl;
        return;
    }
    if(m==1){
        ans = n | n + 1;
        cout << ans << endl;
        return;
    }
    if(n==0&&m>=2){
        cout << (m-1|m|m+1) << endl;
        return;
    }
    if(pow(2,m)>=n){
        int q = 1, t = pow(2,m);
        while (t>n){
            t /= 2;
            q++;
        }
        n += q;
        ans = (n | n + 1 | n + 2);
    }
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
