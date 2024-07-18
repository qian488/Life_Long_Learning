#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<stack>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;

void Solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;
    
}

int main()
{
    ios 
    int t = 1;
    cin >> t;
    while(t--){
        Solve();
    }
    
    //Codeforces Round 943 (Div. 3)_G1	Division + LCP (easy version)
    return 0;
}
/*kmp+二分
#include<iostream>
#include<cstring>
using namespace std;
const int N=2*100010;
int n,k;
bool check(char *s,int mid)
{
	int cnt=0;
	int ne[N];
	char p[N];
	strncpy(p+1,s+1,mid);
	//cout<<p+1<<"---"<<endl;
	for(int i=2,j=0;i<=mid;i++)
	{
		while(j && p[i]!=p[j+1]) j=ne[j];
		if(p[i]==p[j+1]) j++;
		ne[i]=j;
	}
	
	for(int i=1,j=0;i<=n;i++)
	{
		while(j && s[i]!=p[j+1]) j=ne[j];
		if(s[i]==p[j+1]) j++;
		if(j==mid)
		{
			j=0;
			cnt++;
		}
	}
	
	if(cnt>=k) return true;
	else return false;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>k;
		char a[N];
		cin>>a+1;
		
		int l=0,r=n+1;
		while(l<r)
		{
			int mid=(l+r+1)/2;
			if(check(a,mid)) l=mid;
			else r=mid-1;
		}
		cout<<l<<'\n';
	}
	return 0;
}
*/

/*Z函数
#include <bits/stdc++.h>

using i64 = long long;

std::vector<int> Z(std::string s) {
    int n = s.size();
    std::vector<int> z(n + 1);
    z[0] = n;
    for (int i = 1, j = 1; i < n; i++) {
        z[i] = std::max(0, std::min(j + z[j] - i, z[i - j]));
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > j + z[j]) {
            j = i;
        }
    }
    return z;
}

void solve() {
    int n, l, r;
    std::cin >> n >> l >> r;
    
    std::string s;
    std::cin >> s;
    
    auto z = Z(s);
    std::set<int> set;
    std::vector<std::vector<int>> vec(n + 1);
    for (int i = 0; i <= n; i++) {
        vec[z[i]].push_back(i);
        set.insert(i);
    }
    
    std::vector<int> g(n + 1);
    g[0] = n;
    for (int l = 1; l <= n; l++) {
        for (auto i : vec[l - 1]) {
            set.erase(i);
        }
        int x = 0, ans = 1;
        while (true) {
            auto it = set.lower_bound(x + l);
            if (it == set.end()) {
                break;
            }
            ans++;
            x = *it;
        }
        g[l] = ans;
    }
    for (int i = l, len = n; i <= r; i++) {
        while (len > 0 && g[len] < i) {
            len--;
        }
        std::cout << len << " \n"[i == r];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}

*/