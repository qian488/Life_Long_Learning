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
    string a, b;
    cin >> a >> b;
    int ans = 0;
    /*
    int k = 0;
    vector<string> v(n);
    for (int i = 0; i < n;i++){
        v[i] = a.substr(i);
    }
    for(auto e:v){
        //kmp去匹配，匹配到的第一个就是。。。但是忘了。
        for (int i = 0; i < m;i++){
            if (e[0]==b[i])
            {
                
            }
            
        }
    }
    ans = k;
    */
   //dp好像也可以，最长公共子序列，emm爆空间了。。。
   /*
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int k = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i][m] == i) {
            k = i;
        }
    }
    */
   //是我脑抽了。。。
   int i = 0, j = 0;
   while (i < n && j < m){
       if (a[i] == b[j]){
           ans++;
           i++;
           j++;
       }
       else
       {
           j++;
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
    
    //Codeforces Round 943 (Div. 3)_B	Prefiquence
    return 0;
}