#include<iostream>

using namespace std;
//蓝桥第 4 场 小白入门赛--压制二元组的总价值
//是数据范围的问题？还是时间？
//报错是答案错误，只过了样例？题目都看不懂。。。
//理解错题意了
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