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
    int n;
    cin >> n;
    map<string, int> nmp;
    int sum = 0;
    for (int i = 0; i < n;i++){
        string s;
        int c;
        cin >> s >> c;
        nmp[s] = c;
        sum += c;
    }
    string ans = "";
    int tt = sum % n;
    int cnt = 0;
    for(auto e:nmp){
        if (cnt==tt){
            ans = e.first;
            break;
        }
        cnt++;
    }
    cout << ans << endl;
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
