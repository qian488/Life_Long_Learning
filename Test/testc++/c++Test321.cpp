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
const int N=110;

void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> cards(n);
    unordered_map<int, int> mp; 
    for (int i = 0; i < n; i++){ 
        cin >> cards[i];
        mp[cards[i]]++;
    }
    int ans=0;
    bool flag = false;
    for(auto e:mp){
        if(e.second>=k){ 
            flag = true;
            break;
        }
    }
    for (auto p : mp) ans += p.second % (k-1);
    if(ans==n) ans = n;
    else ans = k - 1;
    if(!flag) ans = n;
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
    
    //Codeforces Round 941 (Div. 2)_A	Card Exchange
    return 0;
}