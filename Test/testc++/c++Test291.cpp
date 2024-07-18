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
    ll n;
    cin >> n;
    vector<ll> v(n + 1), w(n + 1);
    for (ll i = 1; i <= n;i++){
        cin >> v[i];
        w[i] = w[i - 1] ^ v[i]; // 前缀异或
    }

    vector<int> l(32), r(32);
    for(auto e:w){
        for (int i = 0; i < 32;i++){ // 统计每个二进制位上的 1 的个数
            r[i] += e >> i & 1; // 遍历w[i],对其二进制表示中的每一位进行检查，如果为 1 则在 r 向量中对应的位置加一，以记录该位上 1 的个数
        }
    }

    ll ans = 0;
    for (ll i = 1; i <= n;i++){
        int d;
        for (int j = 0; j < 32;j++){
            if(v[i]>>j&1)
                d = j; // 找到最高位1的位置
        }

        ll kk = l[d] * r[d] + (i - l[d]) * (n - i + 1 - r[d]); //  左侧 1 的个数乘以右侧 0 的个数 加上 左侧 0 的个数乘以右侧 1 的个数
        ans += kk;

        for (int j = 0; j < 32;j++){
            int tt = w[i] >> j & 1; // 更新 l 和 r 数组，将当前处理的数字 w[i] 的二进制表示中的每一位加到对应的位置上
            r[j] -= tt; // 如果当前位为 1，则右侧对应 1 的个数减一
            l[j] += tt; // 如果当前位为 1，则左侧对应 1 的个数加一
        }
    }
    cout << ans << endl;
}

int main()
{
    ios 
    int t = 1;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    //Codeforces Round 940 (Div. 2) and CodeCraft-23_D. A BIT of an Inequality
    return 0;
}