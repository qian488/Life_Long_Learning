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
    string s;
    cin >> s;
    ll ans = 0;
    vector<int> v;
    for (int i = 0; i < s.length();i++){
        if(s[i]=='1'){
            v.push_back(1);
        }else{
            if(!v.empty()) ans += v.size()+1;
            //cout << ans << " ";
        }
    }
    cout << ans << endl;
}

int main()
{
    ios 
    int t = 1;
    cin >> t;
    while(t--){
        Solve();
    }
    
    //Educational Codeforces Round 165 (Rated for Div. 2)
    return 0;
}