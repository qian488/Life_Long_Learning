#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
//think-cell Round 1 C	Lexicographically Largest
using namespace std;
typedef long long ll;
int main() 
{
    int t;
    cin >> t;

    while (t--) 
    {
        int n;
        cin >> n;

        map<ll, ll> m;
        for (ll i = 1; i <= n; i++)
        {//每个值c都会增加i（序列中的当前位置）并用作映射中的键。相应的值会递增以跟踪其频率。
            ll c;
            cin >> c;
            m[c + i]++;
        }
        vector<ll> ans;
        while (!m.empty())
        {//m中key是数值，value是个数
            pair<ll,ll> it = *m.rbegin();//获取映射中的最后一个（最大的）键值对
            m.erase(it.first);

            ans.push_back(it.first);
            it.second--;
            if (it.second)
            {
                it.first--;
                m[it.first] += it.second;
            }
            
        }
        for(auto e:ans)
        {
            cout << e << " ";
        }
        cout << endl;
    }

    return 0;
}