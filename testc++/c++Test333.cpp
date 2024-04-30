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
    cin>>n;
    vector<int> v(n+1);
    for (int i = 1; i <= n;i++){
        cin >> v[i];
    }
    int ans = 3;
    for (int i = 1; i <= n;i++){
        for (int j = i + 1; j <= n;j++){
            if(j==v[i]&&v[j]==i)
                ans = 2;
        }
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
    
    //Educational Codeforces Round 165 (Rated for Div. 2)
    return 0;
}