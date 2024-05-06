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
    int n, k;
    cin >> n >> k;
    vector<int> p(n), q(n);
    for (int i = 0; i < n;i++){ 
        cin >> p[i];
        q[i] = p[i];
    }
    if(k==1||k>n){
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i < k - 1; i++)
    {
        q[i] = p[i - 1];
    }
    q[0] = p[k - 1];
    q[k - 1] = p[k - 2];
    for(auto e:q){
        cout << e << " ";
    }
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