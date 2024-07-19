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
    int n = s.size();
    int ans = -1;
    for (int i = 0; i < n;i++){
        string t = s.substr(i) + s.substr(0, i);
        ll k = (t[t.size() - 2] - '0') * 10 + (t[t.size() - 1] - '0');
        //cout<<t<<" "<<k<<endl;
        if(k%4==0){ 
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}

int main()
{
    ios 
    int t = 1;
    //cin >> t;
    while(t--){
        Solve();
    }
    
    return 0;
}