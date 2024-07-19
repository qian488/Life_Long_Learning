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
#include<ranges>
//c++20标准
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
    int n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        a[i] ^= a[i - 1];
    }

    map<int, vector<int>> pos;
    for(int i=0;i<=n;i++) pos[a[i]].push_back(i);

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int tt = *prev(ranges::upper_bound(pos[a[l - 1]], r));//这个表达式返回在pos[a[l - 1]]范围内小于等于r的最后一个元素的迭代器。
        int kk = *ranges::lower_bound(pos[a[r]], l - 1);//查找在pos[a[r]]范围内第一个大于等于l - 1的元素的迭代器。
        cout << (kk < tt ? "YES" : "NO") << endl;
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
    
    //Codeforces Round 943 (Div. 3)_F	Equal XOR Segments
    return 0;
}