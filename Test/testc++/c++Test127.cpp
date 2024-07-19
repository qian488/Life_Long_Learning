#include<iostream>
#include<algorithm>
using namespace std;
//2023牛客跨年--嘤嘤的悬崖
//从这里开始会备注好题目出处，以便万一回顾的时候需要看题面
int main()
{
    int n;
    cin>>n;
    int ans=-1e9+1;
    int l=0, r=0;
    for(int i=1;i<=n;i++)
    {
        int x, y;
        cin>>x>>y;
        ans=max(ans,y-l);
        l = x;
        r = y;
    }
    cout<<ans;
    return 0;
}