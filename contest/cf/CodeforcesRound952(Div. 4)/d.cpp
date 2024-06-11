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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    // vector<pii> v;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cin >> g[i][j];
            // if(g[i][j]=='#') v.push_back({i+1, j+1});
        }
    }
    /*
    if(v.size()==1){
        cout << v[0].first << " " << v[0].second << endl;
        return;
    }
    */
    int x, y;
    bool kk = false;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            if(g[i][j]=='#'){
                x = i + 1;
                y = j + 1;
                kk = true;
                break;
            }
        }
        if(kk) break;
    }
    string s = "";
    for (int i = 0; i < n;i++){
        if(g[i][y-1]=='#')s += g[i][y - 1];
    }
    int tt = s.size() / 2;
    x += tt;
    cout << x << " " << y << endl;
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
