#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//Codeforces Round 927 (Div. 3)_B. Chaya Calendar
const int N = 1e6 + 10;
typedef long long ll;
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