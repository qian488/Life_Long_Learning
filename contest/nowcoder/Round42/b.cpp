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
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    string s;
    cin>>s;
    ll ans=0;
    for(int i=0,j=0;i<s.size();i++){
        if(s[i]=='R'){
            if(j==n-1){ 
                ans+=a[j];
            }else{
                j++;
                ans+=a[j];
            }
        }else{
            if(j==0){ 
                ans+=a[j];
            }else{
                j--;
                ans+=a[j];
            }
        }
        //cout<<a[j]<<" "<<j<<endl;
    }
    cout<<ans%MOD<<endl;
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
