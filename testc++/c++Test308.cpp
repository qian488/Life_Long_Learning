#include<bits/stdc++.h>
//蓝桥第 9 场 小白入门赛——无理数位数查询
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=2e5+10;
//错解
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        ll a, b;
        cin >> a >> b;
        string s = "";
        for (int i = 1; i <= a;i++)
        {
            if((((i - 1) % b) + 1)==10){
                int t = (((i - 1) % b) + 1);
                s += to_string(i / 10);
                s += to_string(i % 10);
                i += 2;
            }else{
                s += to_string(((i - 1) % b) + 1);
                i++;
            }
        }

        char ans = s[a - 1];
        cout << ans << endl;
    }
    
    return 0;
}
/*
//不懂
#include<iostream>
using namespace std;
typedef long long ll;
ll calc(ll m, ll k)
{
    ll res = 1;
    while (--k) res *= m;
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m, sum = 0, k = 1;
        cin >> n >> m;
        while (sum + (m - 1) * k * calc(m, k) < n) 
        {
                sum += (m - 1) * k * calc(m, k);
                k++; 
        }
        ll u = n - sum;
        ll a = calc(m, k) - 1 + u / k;
        ll b = u % k;
        if (b == 0) cout << a % m<<endl;
        else 
        {
            a++;
            a = a / (calc(m, k - b + 1));
            cout << a % m << endl;
        }
    }
}
*/
/*
//二分
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
ll n,m;
string get(ll x,ll p){
  string s="";
  while(x){
    s+=char(x%p+'0');
    x/=p;
  }
  reverse(s.begin(),s.end());
  return s;
}
ll tr(string s,ll p){
  if(s=="")return 0;
  ll res=0,cnt=1;
  for(int i=s.length()-1;i>=0;i--){
    res+=(s[i]-'0')*cnt;
    cnt=cnt*p;
  }
  return res;
}
pair<bool,ll> check(ll x,ll p){
  string s=get(x,p);
  ll len=s.length();
  string a="";
  ll ans=0;
  for(int i=1;i<len;i++){
    
    ans+=(tr(a+char(p-1+'0'),p)-tr(a,p))*i;
    a+=char(p-1+'0');
    
  }

  ans+=(tr(s,p)-tr(a,p))*len;
  return {ans>=n,ans};
}
int main(){
  int t;
  cin>>t;
  while(t--){

    scanf("%lld %lld",&n,&m);
    ll l=1,r=1e17,ans=-1;
    while(l<=r){
      ll mid=(l+r)/2;
      auto p=check(mid,m);
      if(p.first){
        r=mid-1;
        ans=mid;
      }
      else{
        l=mid+1;
      }
    }
    
    auto p=check(ans,m);
    ll c=p.second;
    string s=get(ans,m);

    ll d=c-n;
    cout<<s[int(s.length())-1-d]<<"\n";
    
  }
  return 0;
}
*/