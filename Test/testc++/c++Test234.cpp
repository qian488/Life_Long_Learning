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
    map<ll, int> m;
    m[0] = n;
    ll ans = 1;

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

/*AC代码
#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t;
    cin >> n >> t;
    vector<ll> score(n);
    map<ll, int> mp;
    mp[0] = n;
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        if (--mp[score[a]] == 0) mp.erase(score[a]);
        score[a] += b;
        ++mp[score[a]];
        cout << mp.size() << '\n';
    }
}

*/
