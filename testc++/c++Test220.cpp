#include <iostream>
using namespace std;
//蓝桥云课第 6 场 小白入门赛--你不干？有的是帕鲁干！
//找规律
//endl换\n就可以过。。。
typedef long long ll;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    ll x;
    cin>>x;
    
    if(x==0)
    {
      cout<<"No"<<endl;
    }
    else if(x%8==0)
    {
      cout<<"Yes"<<endl;
      ll n=x/8;
      cout<<2*n-1<<" "<<2*n+1<<endl;
    }
    else
    {
      cout<<"No"<<endl;
    }
  }
  return 0;
}