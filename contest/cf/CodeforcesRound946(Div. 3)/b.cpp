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
#define MOD 100000000
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;

void Solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = s, ans = s;
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(),t.end()),t.end());
    //cout << t << endl;
    int m = t.size();
    unordered_map<char, char> tmp;
    for (int i = 0, j = m - 1; i <= j; i++, j--){
        tmp[t[i]] = t[j];
        tmp[t[j]] = t[i];
    }
    /*
    for(auto e:tmp){
        cout << e.first << " " << e.second << endl;
    }
    */
    for (int i = 0; i < n;i++){
        ans[i] = tmp[s[i]];
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
    
    return 0;
}
