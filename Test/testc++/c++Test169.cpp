#include<iostream>
using namespace std;
//集美大学"第15届蓝桥杯大赛(软件类)"校内选拔赛--背单词
//模拟
//当2 1 4 进入循环，可以整体求
typedef long long ll;

int main()
{
    ll n;
    int m;
    cin>>n>>m;
    ll ans=0;
    while(n>0)
    {
        ans++;
        n-=m;
        if(m%2) m=3*m+1;
        else m/=2;
        if(m==2||m==1||m==4)
        {
            ans+=(n/7)*3;
            n%=7;
        }
    }
    cout<<ans;
    return 0;
}