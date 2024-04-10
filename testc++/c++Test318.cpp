#include<bits/stdc++.h>
//蓝桥--子串分值和
using namespace std;
typedef long long ll;
#define endl "\n"
const int N = 1e6 + 10;
//60分?
int main()
{
	string s;
	cin>>s;
	ll ans = s.size();
	for(int i=0;i<s.size();i++)
	{
		unordered_map<char, int> mp;
		mp[s[i]]++;
		for(int j=i+1;j<s.size();j++)
		{
			mp[s[j]]++;
			ans += mp.size();
		}
	}
	cout<<ans<<endl;
    return 0;
}
/*
#include <iostream>
using namespace std;
int last[26];
int main() {
    string s;
    cin >> s;
    s = " " + s;
    long long res = 0;
    int n = s.size();
    for (int i = 1; i < n; ++i) {
        res +=(long long) (n - i) * (i - last[s[i] - 'a']);
        last[s[i] - 'a'] = i;
    }
    cout << res;
    return 0;
}
*/