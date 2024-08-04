#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl "\n"
#define Awith {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int N = 2e5 + 10;

void Solve(void){
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> mp = {{'A', 0}, {'B', 0}, {'C', 0}, {'D', 0}, {'?', 0}};
    for (char c:s)
    {
        mp[c]++;
    }
    ll ans = 0;
    for(auto [x,y]:mp){
        if(x=='?') continue;
        if(y<=n){ 
            ans += y;
        }else{
            ans += n;
        }
    }
    cout << ans << endl;
}

int main(){
    Awith
    int t = 1;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}