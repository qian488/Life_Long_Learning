#include<bits/stdc++.h>
//10
using namespace std;
typedef long double ld;
typedef long long ll;
#define endl "\n"
const int N = 1e6 + 10;

struct node{
	ld k,b;
}l[N];

int main()
{
	int n;
	cin>>n;
	ll ans=1;
	set<pair<ld,ld>> line;
	for(int i=0;i<n;i++)
	{
		ld k,b;
		cin>>k>>b;
		line.insert({k,b});
	}
	int m=0;
	for(auto e:line)
	{
		l[m++]={e.first,e.second};
	}
	for(int i=0;i<m;i++)
	{
		set<pair<ld,ld>> tt;
		for(int j=0;j<i;j++)
		{
			ld k1=l[i].k;
			ld k2=l[j].k;
			ld b1=l[i].b;
			ld b2=l[j].b;
			if(k1==k2) continue;
			ld x1=(b2-b1)/(k1-k2);
			ld y1=k1*x1+b1;
			tt.insert({x1,y1});
		}
		ans+=tt.size()+1;
	}
	cout<<ans<<endl;
    return 0;
}