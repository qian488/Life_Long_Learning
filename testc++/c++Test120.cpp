#include<iostream>
#include<queue>
using namespace std;
//终于蹲到一题用堆数据结构的题了
//集美大学"第15届蓝桥杯大赛(软件类)"校内选拔赛--堆
//好吧，手写不会，cv题解吧。。。

typedef long long ll;
template <class T>
using max_heap = priority_queue<T>;
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<>>;
void solve()
{
    int Q;
    cin >> Q;
    min_heap<ll> q;
    ll offset = 0;
    while (Q--)
    {
        int op;
        cin >> op;
        ll x;
        if (op == 1)
        {
            cin >> x;
            q.push(x - offset);
        }
        else if (op == 2)
        {
            auto ans = q.top() + offset;
            q.pop();
            cout << ans << endl;
        }
        else if (op == 3)
        {
            cin >> x;
            offset += x;
        }
    }
}
int main()
{
    solve();
    return 0;
}

/*参考

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int heap[N];      //堆
int ph[N];     //存放第k个插入点的下标
int hp[N];     //存放堆中点的插入次序
int sizes;  // sizes 记录的是堆当前的数据多少

void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]); // 交换左指向右的指针
    swap(hp[a], hp[b]); // 交换右指向左的指针
    swap(heap[a], heap[b]); // 交换值
}

void down(int i)
{
    int t = i;
    if(2 * i <= sizes && heap[2 * i] < heap[t]) t = 2 * i;
    if(2 * i + 1 <= sizes && heap[2 * i +1] < heap[t]) t = 2 * i + 1;
    if(t != i)
    {
        heap_swap(i, t);
        down(t);
    }
}

void up(int i)
{
    int t = i;
    if(i / 2 && heap[i / 2] > heap[t]) t = i / 2;
    if(t != i)
    {
        heap_swap(t, i);
        up(t);
    }
}
int main()
{
    
    int n, m = 0; // m表示第几个插入的数
    cin >> n;
    while (n -- )
    {
        int k, x;
        string opt;
        cin >> opt;
        if(opt == "I") // 插入一个数x：在堆的末尾位置插入
        {
            cin >> x;
            sizes ++;
            m ++;
            ph[m] = sizes, hp[sizes] = m;
            heap[sizes] = x;
            up(sizes);
        }
        else if(opt == "PM") cout << heap[1] << endl;
        else if(opt == "DM")
        {
            heap_swap(1, sizes);
            sizes --;
            down(1);
            
        }
        
        else if(opt == "D") // 删除第k个插入的数
        {
            cin >> k;
             // 将第k次插入的元素，转换为堆中的下标
            k = ph[k]; // 删除第k个插入的数，就先要找到第k个插入的数的下标（位置）
            heap_swap(k, sizes);
            sizes --;
            down(k);
            up(k);
        }
        else if(opt == "C")// 修改第k个插入的数
        {
            cin >> k >> x;
            k = ph[k]; // // 修改第k个插入的数，就先要找到第k个插入的数的下标（位置）
            heap[k] = x;
            down(k);
            up(k);
        }
        
        
    }
    
    return 0;
}
*/

/*没写出来
const int N=1e6+10;
//h[N]存储堆中的值，h[1]是堆顶，x的左儿子是2x,右儿子是2x+1
//ph[k]存储第k个的点是 第几个插入的
//hp[k]存储堆中下标是k的点是第几个插入的
int h[N],ph[N],hp[N],size;

//交换两个点及其映射关系
void heap_swap(int a,int b)
{
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a],hp[b]);
    swap(h[a],h[b]);
}

void down(int u)
{
    int t=u;
    if(u*2<=size&&h[u*2]<h[t]) t=u*2;
    if(u*2+1<=size&&h[u*2+1]<h[t]) t=u*2+1;
    if(u!=t)
    {
        heap_swap(u,t);
        down(t);
    }
}

void up(int u)
{
    while(u/2&&h[u]<h[u/2])
    {
        heap_swap(u,u/2);
        u>>1;
    }
}

int main()
{
    int Q;
    cin >> Q;
    while (Q--)
    {
        int q, x;
        cin >> q;
        if (q==1)
        {
            cin >> x;
            h[++size] = x;
            up(size);
        }
        else if(q==2)
        {
            cout << h[1] << endl;
            h[1] = h[size];
            size--;
            down(1);
        }
        else if(q==3)
        {
            cin >> x;
            for (int i = 1; i <= size; i++)
            {
                h[i] += x;
                down(i);
                up(i);
            }
        }
    }
    return 0;
}
*/