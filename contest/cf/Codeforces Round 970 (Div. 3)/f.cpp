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

ll f(int x){
    ll ans=1;
    for(int i=1;i<=x;i++){
        ans*=i;
    }
    return ans;
}

ll qmi(ll x,ll n){
    ll res=1;
    while (n)
    {
        if (n&1)
        {
            res=res*x%MOD;
            x=x*x%MOD;
            n>>=1;
        }
        
    }
    return res;
}

// TODO

void Solve()
{

    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    ll Q = f(n)/(f(2)*f(n-2));
    ll P = 0;
    for(int i=0;i<n;i++){
        for (int j = i+1; j < n; j++)
        {
            cout<<(a[i]*a[j])<<" ";
            P += ((a[i]*a[j])%MOD+MOD)%MOD;
        }
    }
    cout<<P<<" "<<Q<<endl;
    // ll ans = P * (qmi(Q,(MOD - 2))%MOD);
    ll ans =P*pow(Q,-1);
    cout<<((ans + MOD) % MOD)<<endl;
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
