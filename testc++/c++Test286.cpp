#include<iostream>
#include<algorithm>
#include<iomanip>
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

bool ttt(int x)
{
    int tt = x;
    while (tt)
    {
        int d = tt % 10;
        if (!(d==0||d==1))
        {
            return false;
        }
        tt /= 10;
    }
    return true;
}

bool check(int x)
{
    if (ttt(x))
    {
        return true;
    }

        bool flag = false;
        int k = x;
        while (k)
        {
            flag=ttt(k);
            k /= 11;
        }
        return flag;
}

void Solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (check(n))
        {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    
}

int main()
{
    ios 
    Solve();
    //Codeforces Round 937 (Div. 4)
    return 0;
}