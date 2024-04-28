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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n;i++) cin >> a[i];
    sort(a.begin(), a.end());
    bool win = false;
    for (int i = n; i >= 1;i--){
        int kk = a[i] - a[i - 1];
        if(kk>0){
            if (!win){
                win = true;
            }else if(kk==1){
                win = false;
            }
            
        }
    }
    cout << (win ? "Alice" : "Bob") << endl;
}

int main()
{
    ios 
    int t = 1;
    cin >> t;
    while(t--){
        Solve();
    }
    
    //Codeforces Round 941 (Div. 2)_C	Everything Nim
    return 0;
}