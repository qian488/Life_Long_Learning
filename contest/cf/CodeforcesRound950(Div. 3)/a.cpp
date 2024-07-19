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
    map<char,int> mp={{'A',0},{'B',0},{'C',0},{'D',0},{'E',0},{'F',0},{'G',0}};
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        mp[s[i]]++;
    }
    int ans=0;
    for(auto e:mp){
        if(m>e.second) ans+=m-e.second;
    }
    cout<<ans<<endl;
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
