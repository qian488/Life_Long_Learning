#include<iostream>
using namespace std;
int main()
{
    int K,N,coin=0;
    cin>>K;               //输入总天数K
    for(N=1;K-N>=0;K-=N++)       //第1天骑士可获得1枚金币
        coin+=N*N;               //在接下来的连续N天里，骑士每天可获得N枚金币
    cout<<coin+K*N;   //输出骑士总共可获得的金币数
    return 0;
}
