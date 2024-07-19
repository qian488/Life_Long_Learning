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
    string k = s;
    unordered_map<char, int> mp;
    for(auto e:s) mp[e]++;
    if(mp.size()>1){
        cout << "YES" << endl;
        sort(s.begin(), s.end());
        if(s!=k){
            cout << s << endl;
        }else{
        swap(s[0], s[s.size() - 1]);
        cout << s << endl;
        }
    }else{
        cout << "NO" << endl;
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