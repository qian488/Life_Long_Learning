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
    string s,k,kk;
    cin >> s;
    k = s;
    sort(k.begin(), k.end());
    if(k==s){
        cout << 1 << endl;
        return;
    }
    int cnt = 0, n = s.size();
    char tt = s[0];
    for (int i = 0; i < n;i++){
        if(tt!=s[i]){
            cnt++;
            tt = s[i];
        }
    }
    if(cnt==1){ 
        cout << 2 << endl;
    }else{
        cout << cnt << endl;
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