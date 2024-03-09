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
//e[]表示节点的值，l[]表示节点的左指针，r[]表示节点的右指针，idx表示当前索引用到了哪个节点
int e[N],l[N],r[N],idx;

//初始化
void init()
{
    //0是左端点，1是右端点
    r[0]=1,l[1]=0;
    idx=2;
}

//在节点a的右边插入一个数x
void insert(int a,int x)
{
    e[idx]=x;
    l[idx]=a,r[idx]=r[a];
    l[r[a]]=idx,r[a]=idx++;
}

//删除节点a
void remove(int a)
{
    l[r[a]]=l[a];
    r[l[a]]=r[a];
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
    //遍历链表输出
}

int main()
{
    ios
    solve();
    //AtCoder Beginner Contest 344_E.Insert or Erase
    //链表
    return 0;
}