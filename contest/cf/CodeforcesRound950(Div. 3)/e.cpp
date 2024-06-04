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
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    vector<int> row(n * m), col(n * m);
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cin >> b[i][j];
            b[i][j]--;
            row[b[i][j]] = i;
            col[b[i][j]] = j;
        }
    }
    // 行变换
    for (int i = 0; i < n;i++){
        int r = row[a[i][0]];
        swap(b[i], b[r]);
        for (int j = 0; j < m;j++){
            row[b[i][j]] = i;
            row[b[r][j]] = r;
        }
    }
    // 列变换
    for (int j = 0; j < m;j++){
        int c = col[a[0][j]];
        for (int i = 0; i < n;i++){
            swap(b[i][j], b[i][c]);
            col[b[i][j]] = j;
            col[b[i][c]] = c;
        }
    }
    if(a==b){
        cout << "YES" << endl;
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
