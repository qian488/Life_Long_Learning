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
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool ok = true;
    int r=sqrt(n);
    if(r*r!=n){
        cout<<"No"<<endl;
        return;
    }
    for (int i = 0; i < r; i++) {
        if (s[i] != '1' || s[n - r + i] != '1') {
            ok = false;
        }
    }
    for (int i = 1; i < r - 1; i++) {
        if (s[i * r] != '1' || s[(i + 1) * r - 1] != '1') {
            ok = false;
        }
        for (int j = 1; j < r - 1; j++) {
            if (s[i * r + j] != '0') {
                ok = false;
            }
        }
    }
    if(ok){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
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
