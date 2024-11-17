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
#include<functional>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
#define lowbit(x) ((x)&(-x))
const int N=2e5+10;

ll qmi(int m,int k,int p)
{
    ll res=1%p,t=m;
    while(k)
    {
        if(k&1) res=res*t%p;
        t=t*t%p;
        k>>=1;
    }
    return res;
}

ll A(int n, int m) {
    ll res = 1;
    for (int i = m; i >= 1; i--) {
        res = ((res % MOD)* n % MOD) % MOD; 
        n--;
    }
    return res;
}

void Solve()
{
    int n;
    cin >> n;
    ll ans = 1,k = 1;
    if(n%2==1){
        k = (n+1)/2;
        n--;
    }
    int len = n/2;
    ans = A(len,len)%MOD;
    ans = (ans*qmi(2,len,MOD))%MOD;
    cout<<(k*ans%MOD)<<endl;

}

int main()
{
    ios 
    int t = 1;
    // cin >> t;
    while(t--){
        Solve();
    }
    
    return 0;
}
