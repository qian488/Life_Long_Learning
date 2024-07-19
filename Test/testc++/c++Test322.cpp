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
const int N=1e6+10;

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n;i++) cin >> g[i];

    bool flag = true;

    if(n!=1){
    bool kk = true;
    char a = g[0][0];
    char b = g[n - 1][0];
    for (int i = 0; i < m;i++){
        if(g[0][i]!=a){ 
            kk = false;
            break;
        }
        if(g[n-1][i]!=b){
            kk = false;
            break;
        }
    }
    if((a!=b)&&(kk)) flag = false;
    }

    if(m!=1){
    bool kk = true;
    char a = g[0][0];
    char b = g[0][m - 1];
    for (int i = 0; i < n;i++){
        if(g[i][0]!=a){ 
            kk = false;
            break;
        }
        if(g[i][m-1]!=b){ 
            kk = false;
            break;
        }
    }
    if((a!=b)&&(kk)) flag = false;
    }
    
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main()
{
    ios 
    int t = 1;
    cin >> t;
    while(t--){
        Solve();
    }
    
    //Codeforces Round 941 (Div. 2)_B	Rectangle Filling
    return 0;
}