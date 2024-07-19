#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//牛客周赛 Round 28--小红的统计区间(hard)
/*
小红拿到了一个数组，她想知道，有多少非空区间满足区间所有元素之和不小于k？
第一行输入两个正整数n,k，用空格隔开。
第二行输入n个正整数a i，代表数组的元素。
输入
5 5
1 4 2 1 3
输出
8
以为是前缀和，但是具体应该是滑窗，计数窗口之和大于等于k,即是答案
hard版本存在负数，不能滑窗
输入
4 5
2 -100 5 6
输出
3
题解给出的方法是离散化+树状数组
又是树状数组，想想怎么去做
不知道为什么只能过10%数据
哦，树状数组中change操作的循环上界应该是N而不是n
*/
typedef long long ll;
const int N = 2e5 + 10;
ll a[N],s[N],tree[N];
ll n, k;
vector<ll> alls;//存储所有待离散化的值

//二分求出对应离散化的值
ll find(ll x)
{//找到第一个大于等于x的位置
    ll l=0,r=alls.size()-1;
    while(l<r)
    {
        ll mid=l+r>>1;
        if(alls[mid]>=x) r=mid;
        else l=mid+1;
    }
    return r+1;//映射到1,2,3...n
}

int lowbit(int x){return x&-x;}

void change(ll x,ll k)
{
    //while(x<=n) tree[x]+=k,x+=lowbit(x);
    while(x<=N) tree[x]+=k,x+=lowbit(x);
}

ll query(ll x)
{
    ll t=0;
    while(x) t+=tree[x],x-=lowbit(x);
    return t;
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for(int i = 1; i <= n; i++) alls.push_back(s[i]), alls.push_back(s[i] - k);

    sort(alls.begin(),alls.end());//排序
    alls.erase(unique(alls.begin(),alls.end()),alls.end());//去重

    ll ans = 0;
    change(find(0), 1);
    for(int i = 1; i <= n; i++)
    {
        ans += query(find(s[i] - k));
        change(find(s[i]), 1);
    }
    cout << ans;
    return 0;
}
/*AC代码
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include "bits/stdc++.h"
using namespace std;
#define ios { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
#define fios ofstream out("test.txt");cout.rdbuf(out.rdbuf())
#define endl "\n"
#define lowbit(x) (x & (-x))
#define INF 0x3f3f3f3f
#define MINF 2147483647
#define eps 1e-6
#define PI acos(-1)
typedef long long LL;
typedef pair<int, int> PII;
#define x first
#define y second
const int N = 200010;

int n;
LL k;
int a[N];
LL s[N], tr[N];
vector<LL> alls;

void add(int x, int c)
{
    for(int i = x; i <= N; i += lowbit(i))
        tr[i] += c;
}

int query(int x)
{
    int res = 0;
    for(int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

int get(LL x)
{
    int l = 0, r = alls.size();
    while(l < r)
    {
        int mid = l + r >> 1;
        if(alls[mid] >= x) r = mid;
        else l = mid + 1;
    }

    return l + 1;
}

int main()
{
    ios;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    for(int i = 1; i <= n; i++) alls.push_back(s[i]), alls.push_back(s[i] - k);

    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    LL res = 0;
    add(get(0), 1);
    for(int i = 1; i <= n; i++)
    {
        res += query(get(s[i] - k));
        add(get(s[i]), 1);
    }

    cout << res << endl;

    return 0;
}
*/