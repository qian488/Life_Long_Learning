#include <iostream>
using namespace std;
//蓝桥云课第 6 场 小白入门赛--3.数学奇才
//不过的原因是爆int了，应该用ll
const int N=1e5+10;
typedef long long ll;
int a[N];
ll s[N];
int main()
{
  int n;
  cin>>n;
  for(int i=1;i<=n;i++) 
  {
    int t;
    cin>>t;
    if(t<0) t*=(-1);
    a[i]=t;
  }
  for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
  cout<<s[n];
  return 0;
}
