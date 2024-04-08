#include<bits/stdc++.h>
//9
using namespace std;
typedef long long ll;
#define endl "\n"
const int N = 1e6 + 10;

int check(string s)
{
	set<char> stt;
	for(int i=0;i<s.size();i++) stt.insert(s[i]);
	return stt.size();
}

int main()
{
	string s;
	cin>>s;
	ll ans=0;
	set<string> tt;
	for(int i=0;i<s.size();i++)
	{
		for(int j=1;j<=s.size();j++)
		{
			string st=s.substr(i,j);
			tt.insert(st);
		}
	}
	for(auto e:tt)
	{
		int t=check(e);
    cout<<e<<endl;
    cout<<t<<endl;
		ans+=t;
	}
	cout<<ans<<endl;
    return 0;
}