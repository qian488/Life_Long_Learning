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
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n;i++) cin >> a[i];
    for (int i = 0; i < n;i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int ans = 0;
    int pos = 0;
    int kk = b.back();
    for (int i = 0; i < n;i++){
        if(a[i]>kk){
            pos = i + 1;
            break;
        }
    }
    if(pos>0){
        ans = n - pos + 1;
    }else {
        for (int i = 0; i < n;i++)
            if(a[i]>b[i]) pos = i + 1;
        if(pos>0) {
            ans = n - pos;
        }
        else{
            ans = pos;
        }
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
    
    //
    return 0;
}