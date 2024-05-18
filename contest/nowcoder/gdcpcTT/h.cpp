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

void Solve(){
    ll res = 0;
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    deque<ll> dq;
    for(ll i = 0; i < n; i++){
        if(s[i] == 'A') dq.push_back(1);
        else dq.push_back(0);
    }
    ll tt = 0;
    for(ll j = 1; j <= min(k, 4 * n); j++){ // 因为每经过至多4次操作，末尾就会多出一个01，所以经过4n次操作，整个串就会变成0101...0101(n为偶数情况下，n为奇数时首位是0，1交替)
        if((dq.front() ^ tt) == 1){ // 如果首位是1，直接反转首位
            ll x = dq.front();
            dq.pop_front();
            dq.push_front(x ^ 1);
        }
        else{//否则反转整个串，再循环左移
            ll x = dq.front();
            dq.pop_front();
            dq.push_back(x);
            tt ^= 1;
        }
    }
    string str = "BA";
    if(k <= 4 * n || n % 2 == 0){
        for(ll x : dq) cout << str[x ^ tt];
        return;
    }

    if((k - 4 * n) % 2 == 1){
        ll x = dq.front();
        dq.pop_front();
        dq.push_front(x ^ 1);
    }
    for(ll x : dq) cout << str[x ^ tt];
}

int main()
{
    ios 
    int t = 1;
    //cin >> t;
    while(t--){
        Solve();
    }
    
    return 0;
}

/*
创建一个双端队列 dq,并将 s 中的每个字符转换为 0 或 1 并存入 dq。
定义一个变量 tt,用于记录反转操作的次数。
接下来,进行最多 min(k, 4 * n) 次的反转操作:
如果队首元素与 tt 的异或值为 1,则直接反转队首元素。
否则,反转整个队列,并更新 tt。
构造一个字符串 str = "BA"。
如果 k 小于等于 4 * n,或者 n 是偶数,则直接输出 dq 中的元素对应的 str 中的字符,并返回。
如果 (k - 4 * n) 是奇数,则再额外反转一次队首元素。
最后,输出 dq 中的元素对应的 str 中的字符。
*/