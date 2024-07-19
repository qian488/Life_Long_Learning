#include<iostream>
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
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        /*
        int a[2] = {0}, b[2] = {0};
        for (int i = 0; i < s.length();i++)
        {
            a[s[i] - '0']++;
        }
        int pos = 0;
        for (int i = 0; i < s.length();i++)
        {
            if(s[i]=='0')
            {
                a[0]--;
                b[0]++;
            }
            else if (s[i]=='1')
            {
                a[1]--;
                b[1]++;
            }
            cout << b[0] << " " << b[1] << " " << a[0] << " " << a[1] << endl;
            if((b[0]>(b[0]+b[1])/2)||(a[1]>(a[0]+a[1])/2)) 
            {
                pos = i;
                break;
            }
        }
        cout << pos << endl;
        */
    }
    
}

int main()
{
    ios 
    Solve();
    //Codeforces Round 935 (Div. 3)_C.Left and Right Houses
    //二分？
    return 0;
}