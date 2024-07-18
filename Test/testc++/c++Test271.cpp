#include<iostream>
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
int n, m;
int tree[N];
int memory[N];
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

int f(int x)
{
    if (x==0) return 0;
    else if (x==1) return 1;
    else if(memory[x]!=-1) return memory[x];
    else if (x>=2&&x%2==0)
    {
        int tt = f(x - 1) + 1;
        memory[x] = tt;
        return memory[x];
    }
    else if(x>=2&&x%2==1)
    {
        int tt = f(x - 1) - 2;
        memory[x] = tt;
        return memory[x];
    }
    
}

void Solve()
{
    memset(memory, -1, sizeof memory);
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n;i++) a[i] = 0;
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        change(l, 1);
        change(r + 1, -1);
    }
    for (int i = 1; i <= n;i++) a[i] = (a[i] + query(i));
    for (int i = 1; i <= n;i++) 
    {
        cout << f(a[i]) << " ";
        //cout << !!a[i] + a[i] / 2 - (a[i] - 1) / 2 * 2 << " ";
    }
}

int main()
{
    ios 
    Solve();
    //莞工天梯赛预选赛_G.蓝白粉幻想
    return 0;
}