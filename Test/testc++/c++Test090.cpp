#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
//直接模拟计算
int main()
{
    int n,ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        v.push_back(t);
    }

    while(v.size()>1)
    {
        sort(v.begin(),v.end());
        int min1=v[0];
        int min2=v[1];
        ans+=min1+min2;
        v.erase(v.begin(),v.begin()+2);
        v.push_back(min1+min2);
    }
    
    cout<<ans<<endl;
    return 0;
}
/*
优先队列
#include <bits/stdc++.h>
using namespace std;
int main()
{
  priority_queue<int,vector<int>,greater<int>>q;
  long long int n,temp,res=0;
  cin>>n;
  for (int i=0;i<n;i++) {
    cin>>temp;
    q.push(temp);
}
  while (q.size()>1) {
    temp=q.top();
    q.pop();
    temp+=q.top();
    q.pop();
    res+=temp;
    q.push(temp);
}
    cout<<res;
}

*/