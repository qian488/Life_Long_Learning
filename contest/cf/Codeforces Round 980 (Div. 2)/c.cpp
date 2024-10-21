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

bool cmp(pii a,pii b){
    if(a.first+a.second==b.first+b.second){
        int ta = max(a.first,a.second);
        int tb = max(b.first,b.second);
        return ta<tb;
    }
    return a.first+a.second<b.first+b.second;
}

void Solve()
{
    int n;
    cin>>n;
    vector<pii> a(n);
    for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
    sort(a.begin(),a.end(),cmp);
    for(auto &[x,y]:a){
        cout<<x<<" "<<y<<" ";
    }
    cout<<endl;
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
