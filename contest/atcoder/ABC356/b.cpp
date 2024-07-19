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
    int n,m;
    cin >> n >> m;
    vector<int> a(m), b(m, 0);
    for(int i=0;i<m;i++)cin>>a[i];
    vector<int> tt;
    int q = n;
    while(q--){
        for (int i = 0; i < m;i++){
            int x;
            cin >> x;
            tt.push_back(x);
        }
        for (int i = 0; i < m;i++){
            b[i] += tt[i];
        }
        tt.clear();
    }
    for (int i = 0; i < m;i++){
        //cout << b[i] << " " << a[i] << endl;
        if(b[i]<a[i]){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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
