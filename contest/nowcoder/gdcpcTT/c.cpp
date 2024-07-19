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
    long double a,b;
    long double x,y;
    cin>>a>>b>>x>>y;
    int k,m;
    cin>>k>>m;
    m=k-m;
    x-=a,y-=b;
    long double tt = 2 * M_PI / k * m;
    long double px = cos(tt), py = sin(tt);
    long double ansx = a + x * px - y * py;
    long double ansy = b + x * py + y * px;
    cout << fixed << setprecision(13) << ansx << " " << ansy << endl;
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
