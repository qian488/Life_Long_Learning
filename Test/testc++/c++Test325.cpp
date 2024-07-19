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
const int N=2e5+10;

void Solve()
{
    int n, k;
    cin >> n >> k;

    int t = 0;
    while ((1 << (t + 1)) <= k){
        t = t + 1;
    }

    vector<int> ans;
    ans.push_back(k - (1 << t));
    ans.push_back(k + 1);
    ans.push_back(k + 1 + (1 << t));

    for (int i = 0; i < 20; i++){
        if (i != t){
            ans.push_back(1 << i);
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;

}

int main()
{
    ios 
    int t = 1;
    cin >> t;
    while(t--){
        Solve();
    }
    
    //Codeforces Round 941 (Div. 2)_D	Missing Subsequence Sum
    return 0;
}