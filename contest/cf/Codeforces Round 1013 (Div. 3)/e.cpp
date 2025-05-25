#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N=2e7+10;

int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}

int primes[N],cnt;//primes[]存储所有素数
bool vis[N];//vis[x]存储x是否被筛掉

void get_primes(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!vis[i]) primes[cnt++]=i;
        for(int j=0;primes[j]<=n/i;j++)
        {
            vis[primes[j]*i]=true;
            if(i%primes[j]==0) break;
        }
    }
}


void solve(){
    int n;
    cin>>n;
    ll ans=0;
    for(int i=1;i<=n;i++){
        cnt=0;
        get_primes(n/i);
        ans+=cnt;
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}