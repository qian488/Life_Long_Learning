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

int f(int x){
    if(x<10) return 1;
    if(x<100) return 2;
    return 3;
}

void Solve()
{
    int n;
    cin >> n;
    vector<pii> ans;
    string s = to_string(n);
    while (s.size()<8){
        s += s;
    }
    int index = 0;
    string t = "";
    while (t.size()<8){
        t += s[index++];
        int kk = stoi(t);
        for (int a = 1; a <= 10000;a++){
            int b = a * n - kk;
            if(b<1||b>min(10000,a*n)) continue;
            if(a*f(n)-b==t.size()) ans.push_back({a, b});
        }
    }
    
    cout << ans.size() << endl;
    for(auto &[a,b] : ans){
        cout << a << " " << b << endl;
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
