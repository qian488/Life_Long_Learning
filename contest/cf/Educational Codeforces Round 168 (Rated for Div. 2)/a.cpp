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
#define INF (ll)2e18
#define MOD 100000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;

int cal_time(string &s) {
    int time = 2; 
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) {
            time += 1;
        } else {
            time += 2;
        }
    }
    return time;
}

void Solve()
{
    string s;
    cin >> s;
    int max_time = 0;
    string ans = s;
    
    for (char c = 'a'; c <= 'z'; c++) {
        for (int i = 0; i <= s.length(); i++) {
            string kk = s.substr(0, i) + c + s.substr(i);
            int time = cal_time(kk);
            if (time > max_time) {
                max_time = time;
                ans = kk;
            }
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
    
    return 0;
}
