#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
//AtCoder Beginner Contest 343_D.Diversity of Scores
//TLE
//DP?映射
//有一个测试点没过
typedef long long ll;
const int N = 2e5 + 10;

int main()
{
    int n, t;
    cin >> n >> t;

    vector<int> v(n+1);
    map<int, int> m;
    m[0] = n;
    int ans = 1;

    for (int i = 1; i <= t; i++)
    {
        int a, b;
        cin >> a >> b;
        
        if (m[v[a]]==1)
        {
            ans--;
        }
        m[v[a]]--;

        v[a] += b;

        if (m[v[a]]==0)
        {
            ans++;
        }
        m[v[a]]++;

        cout << ans << endl;
    }
    
    return 0;
}
/*暴力tle
map<int, int> m;
set<int> s;

int main()
{
    int n, t;
    cin >> n >> t;

    for (int i = 1; i <= n;i++)
    {
        m[i] = 0;
    }

    for (int i = 1; i <= t; i++)
    {
        int a, b;
        cin >> a >> b;
        m[a] += b;
        
        s.clear();
        for (auto e:m)
        {
            s.insert(e.second);
        }
        
        int ans=s.size();
        cout << ans << endl;
    }
    
    return 0;
}
*/


