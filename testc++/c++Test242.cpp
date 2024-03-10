#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N = 1e6 + 10;

void solve()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<vector<string>> v(n);
    for (int i = 0; i < n;i++)
    {
        int t;
        cin >> t;
        for (int j = 0; j < t;j++)
        {
            string x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    int m = s.size();
    vector<int> dp(m, INF);
    for (int i = 0; i < n;i++)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            for(auto e:v[i])
            {
                int len = e.size();
                if (len==j+1&&s.substr(0,len)==e)
                {
                    dp[j] = 1;
                }
                else if(len<=j&&s.substr(j-len+1,len)==e)
                {
                    dp[j] = min(dp[j], dp[j - len] + 1);
                }
                cout << dp[j] << " ";
            }
        }
    }
    if (dp[m - 1] == INF) cout << -1 << endl;
    else cout << dp[m - 1] << endl;
    //for(auto e:dp) cout << e << " ";
}

int main()
{
    ios
    solve();
    //AtCoder Beginner Contest 344_D.String Bags
    //string背包？
    //DP,不太会
    //感觉有点贪心的味道
    return 0;
}
/*AC代码
#include<iostream>
#include<vector>
#include<stack>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string>
#include<random>
#include<functional>
#include<time.h>
#include<cstring>
#include<bitset>
#include<array>
using namespace std;
typedef long long ll;
#define int long long
typedef unsigned long long ull;
typedef long double ld;
#define endl '\n'

signed main() {
    
    // ios::sync_with_stdio(0); cout.tie(0);

    string T;cin>>T;
    int n;cin>>n;
    vector<int> a(n);
    vector<vector<string>> v(n);

    for(int i=0;i<n;i++) {
        cin>>a[i];
        for(int j=0;j<a[i];j++) {
            string x;cin>>x;
            v[i].push_back(x);
        }
    }
    int m=T.size();

    vector<int> dp(m,1e9);

    for(int i=0;i<n;i++) {
        for(int j=m-1;j>=0;j--) {
            for(auto e:v[i]) {
                int len=e.size();
                if(j-len==-1 && T.substr(0,len)==e) {
                    dp[j]=1;
                } else if(j-len>=0 && T.substr(j-len+1,len)==e) {
                    dp[j]=min(dp[j],dp[j-len]+1);
                }
            }
        }
    }

    if(dp[m-1]==1e9) {
        cout<<-1<<endl;
    } else {
        cout<<dp[m-1]<<endl;
    }

    return 0;
}*/