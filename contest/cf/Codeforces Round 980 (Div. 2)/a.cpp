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
    ll a,b;
    cin>>a>>b;

    if(a>=b) return cout<<a<<endl,void();
    
    if((b-a*2)>=0) return cout<<0<<endl,void();
/*
    for(int i=1;i<a;i++){
        if((a-i)>=(b-2*i)){
            cout<<a-i<<endl;
            break;
        }
    }
*/
    cout<<a-(b-a)<<endl;
    
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
