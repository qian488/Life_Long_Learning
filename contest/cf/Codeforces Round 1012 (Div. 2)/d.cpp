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

bool is_prime(int x)
{
    if(x<2) return false;
    for(int i=2;i<=x/i;i++)
    {
        if(x%i==0) return false;
    }
    return true;
}

void Solve()
{
    int n;
    cin>>n;
    vector<int> ans,a,b;
    int idx = max(n/3,1);
    while(!is_prime(idx)&&idx<n) idx++;
    for(int i=idx;i<=idx*2;i++){ 
        if(i>n) continue;
        a.push_back(i);
    }
    for(int i=idx-1;i>=1;i--){ 
        if(i>n) continue;
        b.push_back(i);
    }
    int kk = max(a.size(), b.size());
    for (int i = 0; i < kk; i++) {
        if (i < a.size()) {
            ans.push_back(a[i]);
        }
        if (i < b.size()) {
            ans.push_back(b[i]);
        }
    }
    for(int i=idx*2+1;i<=n;i++) ans.push_back(i);

    for (int e : ans) {
        cout << e << " ";
    }
    cout << endl;

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
