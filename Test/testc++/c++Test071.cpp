#include<iostream>

using namespace std;
//计数佬秒了
//有多少个元数组（x,y,k）能够满足，x*y+z=N；
int main()
{
    int n,ans=0;cin>>n;
    for(int i=1;i<n;i++) 
    {
        ans+=(n-1)/i;
    }
    cout<<ans;
    return 0;
}