#include<iostream>

using namespace std;
//蓝桥第 4 场 小白入门赛--压制二元组的总价值
//是数据范围的问题？还是时间？
//报错是答案错误，只过了样例？题目都看不懂。。。
//理解错题意了
//过20%。。。
//树状数组？！！！又是这个玩意儿，看来要去仔细学学
typedef long long ll;
const ll N = 2e5 + 10;
ll a[N],b[N];
int main()
{
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++) cin>>a[i];
    for(ll i=1;i<=n;i++) 
    {
        int x;
        cin >> x;
        b[x]=i;
    }
    ll sum=0;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=i+1;j<=n;j++)
        {
            if(b[a[i]]<b[a[j]])
            {
                sum+=j-i;
            }
        }
    }
    cout<<sum;
    return 0;
}
/*只过了30%的数据。。。
//问题出现在哪？暂时不明白，先放
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
int n;
int tree[N],A[N],B[N],C[N];

int lowbit(int x){return x&-x;}

void change(int x,int k)
{
    while(x<=n) tree[x]+=k,x+=lowbit(x);
}

int query(int x)
{
    int t=0;
    while(x) t+=tree[x],x-=lowbit(x);
    return t;
}

void solve()
{
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    int k;
    cin>>k;
    A[k]=i;
  } 
  for(int i=1;i<=n;i++)
  {
    int k;
    cin>>k;
    B[i]=A[k];
  }

  for(int i=n;i>0;i--)
  {
    C[i]=query(n)-query(B[i]);
    change(B[i],1);
  }

  memset(tree,0,sizeof tree);
  ll ans=0;
  for(int i=n;i>0;i--)
  {
    ans+=query(n)-query(B[i])-C[i]*B[i];
    change(B[i],B[i]);
  }

  cout<<ans;

}

int main()
{
    ios
    solve();
    return 0;
}
*/
/*AC代码
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=200010;
int n;
int a[N],b[N],tr[N],c[N];
int lowbit(int x)
{
  return x&-x;
}
void add(int x,int y)
{
  for(int i=x;i<=n;i+=lowbit(i))
  {
    tr[i]+=y;
  }
}
int query(int x)
{
  int res=0;
  for(int i=x;i>0;i-=lowbit(i))
  {
    res+=tr[i];
  }
  return res;
}
signed main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    int s;
    cin>>s;
    a[s]=i;
  }
  for(int i=1;i<=n;i++)
  {
    int s;
    cin>>s;
    b[i]=a[s];//b数组已经实现，接着判断顺序对
  }

  for(int i=n;i>0;i--)
  {
    c[i]=query(n)-query(b[i]);
   // cout<<c[i]<<" ";
    add(b[i],1);
  }
  memset(tr,0,sizeof(tr));
  int  sum=0;
  for(int i=n;i>0;i--)
  {
    sum+=query(n)-query(b[i])-c[i]*b[i];
    add(b[i],b[i]);
  }
  cout<<sum;
  return 0;
}*/