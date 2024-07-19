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
int a[N];
int lowbit(int x){return x&-x;}

void solve()
{
    int n;
    cin>>n;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
      cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=i+1;j<=n;j++)
      {
        if(lowbit(a[i]+a[j])==a[i]+a[j])ans++;
        //cout << lowbit(a[i] + a[j]) << " ";
      }
      
    }
    
    cout<<ans;
}

int main()
{
    ios
    solve();
    //蓝桥第 7 场 小白入门赛_4.可结合的元素对
    //其实可以考虑双指针优化的，但是不会。。。算了，暂时过了就行。
    return 0;
}