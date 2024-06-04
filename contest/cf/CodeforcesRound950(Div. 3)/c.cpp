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
    int n, m;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    for (int i = 0; i < n;i++){
        cin >> b[i];
    }
    cin >> m;
    vector<int> d(m);
    vector<int> tt;
    for (int i = 0; i < m;i++){ 
        cin >> d[i];
        tt.push_back(d[i]);
    }
    sort(tt.begin(), tt.end());
    bool ok = true;
    if(find(b.begin(),b.end(),d[m-1])==b.end()){ 
        ok = false;
        cout << "NO" << endl;
        return;
    }
    multiset<int> kk(d.begin(), d.end());
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            
            if(kk.count(b[i])==0){ 
                ok = false;
                break;
            }else{ 
                kk.erase(kk.find(b[i]));
            }
            
           /*
           // 超时？
            if(find(tt.begin(),tt.end(),b[i])==tt.end()){ 
                ok = false;
                break;
            }else{
                for (int j = 0; j < tt.size();j++){
                    if(tt[j]==b[i]){
                        tt.erase(tt.begin() + j);
                    }
                }
            }
            */
        }
    }

    if(ok){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    
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
