#include<iostream>
#include<algorithm>
using namespace std;
//蓝桥小白赛3--召唤坤坤
//问题在于i<j<k,然后求max((w[i]+w[j])/w[k]),故不可以排序，这样会打破ijk
typedef long long ll;
const int N = 1e5 + 10;
ll a[N];
int main()
{
    ll n;
    cin >> n;
    for (ll i = 0; i < n;i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    ll x = a[0], y = a[1], z = a[n - 1];
    ll ans = (x + z) / y;
    cout << ans;
    return 0;
}
/*AC代码
#include<iostream>
using namespace std;
const int N=1e5+10;
int a[N],lmax[N],rmax[N];
int main(){
  int n;
  cin>>n;
  for(int i=1;i<=n;i++) cin>>a[i];

  //先预处理出 lmax,rmax

  int mx=0;
  //lmax[i]标识在1-i中最大值是哪一个（包括i）
  for(int i=1;i<=n;i++)
  {
     if(a[i]>mx) mx=a[i];
     lmax[i]=mx;
  }

  mx=0;
  //rmax[i]表示在i-n当中最大值
  for(int i=n;i>=1;i--)
  {
    if(a[i]>mx) mx=a[i];
    rmax[i]=mx;
  }

  int res=0;
  
  //枚举每一个分母，比较的最大值
  for(int i=2;i<n;i++)
  {
     res=max(res,(lmax[i-1]+rmax[i+1])/a[i]);
  }
  cout<<res<<endl;
  return 0;
}
*/