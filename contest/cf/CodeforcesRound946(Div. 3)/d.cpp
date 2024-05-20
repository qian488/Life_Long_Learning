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
#define MOD 100000000
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;
// N S E W
unordered_map<char, pii> dmp = {{'N', {0, 1}}, {'S', {0, -1}}, {'E', {1, 0}}, {'W', {-1, 0}}};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, kk;
string s;
string ans = "";
// 回溯
// xy表示R,uv表示H
bool dfs(int x,int y,int u,int v){
    if(kk==0&&x==u&&y==v) return true;
    for (int i = 0; i < n;i++){

    }
    return false;
}

void Solve()
{
    cin >> n;
    kk = n;
    cin >> s;
    // dfs?dp?
    if(dfs(0, 0, 0, 0)){
        cout << ans << endl;
    }else{
        cout << "NO" << endl;
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
