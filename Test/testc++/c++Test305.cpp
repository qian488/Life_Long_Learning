#include<bits/stdc++.h>
//蓝桥第 9 场 小白入门赛——字符迁移
using namespace std;
typedef long long ll;
#define endl "\n"
const int N = 2e5 + 10;
//ll k[N];
int n, q;
ll tree[N];

int lowbit(int x){return x&-x;}

void change(int x,int k)//向后修
{//这里的N开大了，实际上是n
    while(x<=n) tree[x]+=k,x+=lowbit(x);
}

int query(int x)//向前查
{
    int t=0;
    while(x) t+=tree[x],x-=lowbit(x);
    return t;
}

int query(int l,int r)//区间和==前缀和之差
{
	return query(r)-query(l-1);
}

int main()
{
    cin >> n >> q;
    string s="0";
    string st;
    cin >> st;
    s += st;
    for (int i = 0; i < q; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        c %= 26;
        change(a, c);
        change(b+1, -c);
    }
    
    for (int i = 1; i < s.size();i++)
    {
        //cout << k[i] << " ";
        //s[i] = ((s[i] - 'a') + k[i] % 26) % 26 + 'a';
        ll t = query(i);
        //cout << t << " ";
        s[i] = ((s[i] - 'a') + t % 26) % 26 + 'a';
    }
    //cout << endl;
    cout << s.substr(1, n) << endl;
    return 0;
}