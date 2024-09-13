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
#define ios {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int N=2e5+10;

void Solve()
{
    ll x11,y11,x12,y12,x21,x22,y21,y22;
    cin>>x11>>y11>>x12>>y12>>x21>>y21>>x22>>y22;
    // 求圆心
    double x1=(x11+x12)*1.0/2,y1=(y11+y12)*1.0/2,x2=(x21+x22)*1.0/2,y2=(y21+y22)*1.0/2;
    double r1=sqrt((x12-x11)*(x12-x11)+(y12-y11)*(y12-y11))*1.0/2,r2=sqrt((x22-x21)*(x22-x21)+(y22-y21)*(y22-y21))*1.0/2;
    double ans=(abs(x1 - x2) + abs(y1 - y2) - sqrt(2.0)*r2);
    cout<< fixed  << setprecision(15) << ans <<endl;
}

int main()
{
    ios 
    ll t = 1;
    cin >> t;
    while(t--){
        Solve();
    }

    return 0;
}
