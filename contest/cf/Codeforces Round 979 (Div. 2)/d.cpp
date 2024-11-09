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

void Solve()
{
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> mx(n + 1,0);
    for(int i = 1; i <= n; i++) mx[i] = max(mx[i - 1], a[i]);
    string s;
    cin >> s;
    s = 'k' + s;
    set<int> st;
    for(int i = 1; i < n; i++) {
        if(s[i] == 'L' && s[i + 1] == 'R' && mx[i] > i) st.insert(i);
    }
    while(q--){
        int pos;
        cin >> pos;
        if(s[pos] == 'L' && s[pos + 1] == 'R' && mx[pos] > pos) st.erase(pos);
        if(s[pos] == 'R' && s[pos - 1] == 'L' && mx[pos - 1] > pos - 1) st.erase(pos - 1);
        if(s[pos] == 'L') s[pos] = 'R';
        else s[pos] = 'L';
        if(s[pos] == 'L' && s[pos + 1] == 'R' && mx[pos] > pos) st.insert(pos);
        if(s[pos] == 'R' && s[pos - 1] == 'L' && mx[pos - 1] > pos - 1) st.insert(pos - 1);
        cout << (st.size() > 0 ? "NO" : "YES") << endl;
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
