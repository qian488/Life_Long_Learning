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
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];

    if(n==1) return cout<<0<<endl,void();

    int x=0;
    for(int i=0;i<n;i++) {
        if(a[i]>x) x++;
        if(a[i]<x) x--;
        b[i]=x;
    }
 
    for(int i=0;i<n-1;i++) b[i+1]=max(b[i],b[i+1]);

    int l=0,r=1e9;
    while(l+1<r) {
        int mid=(l+r)/2;
 
        bool yes=false;
 
        int L=mid;
        for(int i=n-1;i>=0;i--) {
            int val=0;
            if(i>0) val=b[i-1];

            if(val>=L) yes = true;

            if (L > a[i]) L++;
            else L--;

        }

        if(yes) l=mid;
        else r=mid;
    }
    cout<<l<<endl;
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
