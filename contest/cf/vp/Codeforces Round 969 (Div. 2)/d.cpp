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
    vector<int> g[n];
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    string s;
    cin >> s;
    if(s[0] == '?'){
        int a = 0, b = 0, c = 0, d = 0;
        for(int i = 1; i < n; i++){
            if(g[i].size() == 1){
                if(s[i] == '1') a++;
                else if(s[i] == '0') b++;
                else c++;
            }else if(s[i] == '?'){ 
                d++;
            }
        }
        int ans = max(a, b);
        if(a == b){
            if(d%2==0) c--;
            ans += (c + 1) / 2;
        }else{
            ans += c / 2;
        }
        cout << ans << endl;
    }else{
        int a = 0, b = 0;
        for(int i = 1; i < n; i++){
            if(g[i].size() == 1){
                if(s[i] == '?') a++;
                else if(s[i] != s[0]) b++;
            }
        }
        int ans = b + (a + 1) / 2;
        cout << ans << endl;
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
