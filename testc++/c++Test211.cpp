#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//Codeforces Round 927 (Div. 3)_B. Chaya Calendar
#define ios                      \
    {                            \
        ios::sync_with_stdio(0); \
        cin.tie(0);              \
    }
const int N = 1e6 + 10;
typedef long long ll;

void Solve()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 0; i < n;i++)
        {
            ans += a[i] - ans % a[i];
        }
        cout << ans << endl;
    }
    
}

int main()
{
    ios
    Solve();
    //看了题解，但不是很懂意思
    return 0;
}
//被Hacked了
/*
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        ll ans = v[0];
        for (int i = 1; i < n; i++)
        {
            for (int j = v[i]; ; j += v[i]) 
            {
                if (j > ans) 
                {
                    ans = j;
                    break;
                }
            }
            
        }
        cout << ans << endl;
    }
    
    return 0;
}
*/