#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
//莞工集训24.02.24--H
typedef long long ll;
vector<ll> a;
vector<ll> ans;
int main() 
{
    ll x;
    cin >> x;

    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto e : ans) 
    {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}
