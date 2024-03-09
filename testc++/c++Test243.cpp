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
//head存储链表头，e[]存储节点值，ne[]存储节点的next指针，idx表示当前索引用到了哪个节点
int head,e[N],ne[N],idx;

//初始化
void init()
{
    head=-1;
    idx=0;
}

//在链表头插入一个数a
void insert(int a)
{
    e[idx]=a,ne[idx]=head,head=idx++;
}

//将头节点删除，需要保证头节点存在
void remove()
{
    head=ne[head];
}

void solve()
{
    int n;
    cin >> n;
    init();
    while(n--)
    {
        int x;
        cin >> x;
        insert(x);
    }
    int q;
    while (q--)
    {
        int op;
        cin >> op;
        if (op==2)
        {
            int x;
            cin >> x;
            remove(x);
        }
        else if(op==1)
        {
            int x, y;
            cin >> x >> y;
            insert(x, y);
        }
    }
    
}

int main()
{
    ios
    solve();
    //AtCoder Beginner Contest 344_E.Insert or Erase
    //链表
    return 0;
}