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
    int a, b, c;
    cin >> a >> b >> c;
    int sum = 0, ans = 0;
    sum += a + b + c;
    if(sum%2){ 
        cout << -1 << endl;
        return;
    }
    if (a==0&&b==0&&c==0)
    {
        cout << 0 << endl;
        return;
    }
    if(a==0&&b==0&&c!=0){
        cout << 0 << endl;
        return;
    }
    if(a==0&&b!=0&&c!=0){
        cout << min(b, c) << endl;
        return;
    }
    if(a+b<=c){
        ans = a + b;
    }else{
        ans += a;
        ans += (b + c - a) / 2;
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
