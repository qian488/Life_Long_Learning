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
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        char c;
        cin >> a >> c >> b;
        if (a==0)
        {
            cout << setw(2) << setfill('0') << 12 << c << setw(2) << setfill('0') << b;
            cout << " AM" << endl;
        }
        else if (a>12)
        {
            cout << setw(2) << setfill('0') << a-12 << c << setw(2) << setfill('0') << b;
            cout << " PM" << endl;
        }
        else if (a==12)
        {
            cout << setw(2) << setfill('0') << a << c << setw(2) << setfill('0') << b;
            cout << " PM" << endl;
        }
        else{
            cout << setw(2) << setfill('0') << a << c << setw(2) << setfill('0') << b;
            cout << " AM" << endl;
        }
        
    }
    
}

int main()
{
    ios 
    Solve();
    //Codeforces Round 937 (Div. 4)_C.Clock Conversion
    return 0;
}