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
    int n;
    cin>>n;
    int cnt0=0,cnt1=0;

    string s;
    cin>>s;
    for(int i=0;i<n;i++) {
        if(s[i]=='0') cnt0++;
        else cnt1++;
    }
 
    string t;
    cin>>t;
    for(int i=0;i<n-1;i++) {
        if(cnt0*cnt1==0) {
            cout<<"NO\n";
            return;
        }
        if(t[i]=='0') {
            cnt1--;
        } else {
            cnt0--;
        }
    }
    cout<<"YES\n";
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
