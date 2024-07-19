#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//程序自动分析
//离散化+并查集
/*
有一个测试点re
不知道是什么情况
段错误，就是说数组越界
mod数太大，p[]开的小了，mod的数要在p[]开的区间内
*/
typedef long long ll;
#define mod 1000007
const int N = 1e5 + 10;

ll p[10 * N];
ll a[N], b[N];
int find(int x)
{
    if (p[x]!=x)
    {
        p[x] = find(p[x]);
    }
    return p[x];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, len = 0, flag = 0;
        cin >> n;

        for (int i = 1; i <= (10*N); i++)
        {
            p[i] = i;
        }
        
        for (int i = 1; i <= n; i++)
        {
            ll x, y, e;
            cin >> x >> y >> e;
            x %= mod;
            y %= mod;
            if (e==1)
            {
                //合并x,y
                int t1 = find(x);
                int t2 = find(y);
                p[t1] = t2;
            }
            else
            {
                a[++len] = x;
                b[len] = y;
            }
        
        }
        
        for (int i = 1; i <= len; i++)
        {
            if (find(a[i])==find(b[i]))
            {
                flag = 1;
                break;
            }
            
        }
        if (flag==1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }

    }
    
    return 0;
}
/*
离散化板子不知道要怎么和并查集的板子缝起来，看题解是可以直接模一个大数

vector<int> alls;

sort(alls.begin(), alls.end()); // 将所有值排序
alls.erase(unique(alls.begin(), alls.end()), alls.end());   // 去掉重复元素

int lsh(int x)
{
    int l = 0, r = alls.size() - 1;
    while (l<r)
    {
        int mid = l + r >> 1;
        if (alls[mid]>=x)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return r + 1;
}

*/