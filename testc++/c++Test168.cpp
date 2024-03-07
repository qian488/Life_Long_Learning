#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
//集美大学"第15届蓝桥杯大赛(软件类)"校内选拔赛--玩《Minecraft》的贝贝
//1 2 或者 2 1
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        if(m>n) swap(n,m);
        if(2*m>n) cout<<(m+n)/3<<endl;
        else cout<<m<<endl;
    }
    return 0;
}