#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//牛客练习赛120--抽奖黑幕
//最大值最小，应该是二分答案,但是二分的边界，或者说二分的条件是什么
//好像不用，要使去掉最大值最小值的总和最大，那就是再加入原本最大的数。
//啊？难道不是吗？
//卧槽！没有考虑全是同一个数的情况，全是同一个数，那使和最大值最小的数就是1
typedef long long ll;
vector<ll> v;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        ll n;
        cin >> n;
        v.clear();
        for (ll i = 0; i < n-1; i++)
        {
            ll t;
            cin >> t;
            v.push_back(t);
        }
        sort(v.begin(), v.end());
        if (v[0]==v[n-2])
        {
            cout << 1 << endl;
        }
        else
        {
            cout << v[n-2] << endl;
        }
        
    }
    
    return 0;
}