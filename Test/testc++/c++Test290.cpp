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
const int N=1e6+10;

void Solve()
{
    int n, k;
    cin >> n >> k;
    if(n==1) cout << k << endl;
    else {
        int idx = 1;
        while (idx*2+1<=k)
        {
            idx = idx * 2 + 1;
        }
        cout << idx << " " << k - idx << " ";
        for (int i = 2; i < n;i++) cout << "0 ";
        cout << endl;
    }
}

int main()
{
    ios 
    int t = 1;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    //Codeforces Round 940 (Div. 2) and CodeCraft-23_B - A BIT of a Construction
    return 0;
}