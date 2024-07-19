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
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        for (int j = 0; j < m; j++){
            v[i][j] = 3 - (s[j] - '0');
        }
	}
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j=0;j<m;j++) {
            v[i][j] += s[j] - '0';
            v[i][j] %= 3;
        }
    }

    bool ok = true;
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < m - 1; j++){
            int kk = 3 - v[i][j];
            v[i][j] = (v[i][j] + kk) % 3;
            v[i + 1][j + 1] = (v[i + 1][j + 1] + kk) % 3;
            v[i][j + 1] = (v[i][j + 1] + kk * 2) % 3;
            v[i + 1][j] = (v[i + 1][j] + kk * 2) % 3;
        }
    }

    for(auto e:v) {
		ok &= count(e.begin(),e.end(),0LL)==m;
	}
 
	if(ok) {
        cout << "YES" << endl;
    } else {
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
