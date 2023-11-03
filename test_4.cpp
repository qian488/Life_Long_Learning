#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool check(vector<int> num,int mid,int k)
{
  int ans=1;
  for(int i=0,j=0;i<num.size();i++)
  {
    if(mid<num[i]-num[j])
    {
      ans++;
      j = i;
    }
  }
  return ans<=k;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    for(int i=0;i<n;i++)
    {
      cin>>num[i];
    }
    sort(num.begin(),num.end());

    int l=0,r=num.back()-num.front();
    while(l<r)
    {
      int mid=l+r>>1;
      if(check(num,mid,k))
      {
        r=mid;
      }
      else
      {
        l=mid+1;
      }
    }
    cout<<r;
    return 0;
}