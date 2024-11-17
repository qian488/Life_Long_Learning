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
    int n = 10;
    vector<pii> v(n);
    int sum = 0;
    
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v[i].second = x % 10;
        v[i].first = x / 10;
        sum += v[i].second;
    }
    
    for(int i = 0; i < (1 << n); i++){
        int kk = sum;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                kk -= v[j].second;
                kk += v[j].first;
            }
        }
        if(kk == 20){
            cout << "YES" << endl;
            return;
        }
    }
    
    cout << "NO" << endl;
}

int main()
{
    ios 
    int t = 1;
    // cin >> t;
    while(t--){
        Solve();
    }
    
    return 0;
}
