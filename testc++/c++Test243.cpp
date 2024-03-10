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
int A[N];
//初始化
void init()
{
    head=-1;
    idx=0;
}

//头插法
//在链表头插入一个数a
void insert(int a)
{
    e[idx]=a,ne[idx]=head,head=idx++;
}

//将头节点删除，需要保证头节点存在
//删除节点
void remove(int x)
{
    // 查找要删除节点的前一个节点
    for (int i = head; ne[i] != -1;i = ne[i])
    {
        if (e[ne[i]] == x) 
        {
            // 找到要删除节点的前一个节点
            ne[i] = ne[x];
            ne[x] = -1;
            return;
        }
        
    }

}

//在a后边加入b
void insert(int a,int b)
{
    // 查找要插入节点的前一个节点
    for (int i = head; ne[i] != -1;i = ne[i])
    {
        if (e[ne[i]] == a) 
        {
            // 找到要插入节点的前一个节点
            ne[++head] = ne[i];
            e[head] = b;
            ne[i] = head;
            return;
        }
        
    }
}

void solve()
{
    int n;
    cin >> n;
    init();
    
    for (int i = 0; i < n;i++)
    {
        int x;
        cin >> x;
        insert(x);
    }
    
    /*
    for (int i = 0; i < n;i++) cin >> A[i];
    for (int i = n - 1; i >= 0;i--) insert(A[i]);
    */
    for(auto i:e)if(i!=0)cout << i << " ";
    cout << endl;
    for(auto i:ne)if(i!=0)cout << i << " ";
    cout << endl;

    int q;
    cin >> q;
    while (q--)
    {
        int op;
        cin >> op;
        if (op==2)
        {//删除x元素
            int x;
            cin >> x;
            remove(x);
        }
        else if(op==1)
        {//在x后插入y
            int x, y;
            cin >> x >> y;
            insert(x, y);
        }
        for(int i=head;i!=-1;i=ne[i]) cout << e[i] << " ";
        cout << endl;
    }
    for(auto i:e)if(i!=0)cout << i << " ";
    cout << endl;
    for(auto i:ne)if(i!=0)cout << i << " ";
    cout << endl;
    //遍历链表输出
    for(int i=head;i!=-1;i=ne[i]) cout << e[i] << " ";
    cout << endl;
}

int main()
{
    ios
    solve();
    //AtCoder Beginner Contest 344_E.Insert or Erase
    //手撕链表
    return 0;
}