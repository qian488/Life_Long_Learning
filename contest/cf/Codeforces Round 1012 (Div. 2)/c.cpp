#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<array>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<stack>
#include<queue>
#include<string>
#include<bitset>
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
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    
    set<array<int,3>> s,t; // t存关键 s存全部 set默认排序
	for (int i=0; n>0 ;i++){
		for (int j=0; j<=i ;j++,n--){
            // a=i−j,b=j 
			int x=3*(i-j)+1,y=3*j+1;
			t.insert({x+y,x,y});
			s.insert({x+y,x,y});
			s.insert({x+y+1,x+1,y});
			s.insert({x+y+1,x,y+1});
			s.insert({x+y+4,x+1,y+1});
		}
	}
	
	for (int x:a){
		if (x){
			auto it=*s.begin();
			s.erase(s.find(it));
			if (t.find(it)!=t.end()) t.erase(t.find(it));
			cout<<it[1]<<" "<<it[2]<<endl;
		}else{
			auto it=*t.begin();
			s.erase(s.find(it));
			t.erase(t.find(it));
			cout<<it[1]<<" "<<it[2]<<endl;
		}
	}
}

int main()
{
    ios 
    int t = 1;
    cin >> t;
    while(t--){
        Solve();
    }
    
    return 0;
}
