#include<iostream>
#include<algorithm>
using namespace std;
//蓝桥小白赛3--奇怪的段
//DP,前i个元素划分成前j段，根据第i个位置和i-1个位置是否属于同一段划分状态
typedef long long ll;
const int N=1e5+10;
const int M=205;
const ll MIN=2e18+10;
ll a[N],b[M];
ll dp[N][M];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
      cin>>a[i];
    }
    for(int i=1;i<=k;i++)
    {
      cin>>b[i];
    }
    
    for(int i=0;i<=n;i++)
    {
      for(int j=0;j<=k;j++)
      {
        dp[i][j]=-MIN;
      }
    }
    
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=k;j++)
      {
          dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i] * b[j];
      }
    }
    cout<<dp[n][k];
    return 0;
}