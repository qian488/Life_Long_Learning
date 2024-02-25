#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//莞工集训24.02.17--B
typedef long long ll;
ll getN(ll n) 
{
    ll res = 0;
    while (n > 0) 
    {
        res += n % 10;
        n /= 10;
    }
    return res;
}

ll cmp(ll x, ll y) 
{
    ll nx = getN(x);
    ll ny = getN(y);
    
    return (nx == ny) ? (x < y) : (nx < ny);
}

int main()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> num;
    for (ll i = 1; i <= n; i++) 
    {
        num.push_back(i);
    }
    sort(num.begin(), num.end(), cmp);

    cout << num[m - 1] << endl;

    return 0;
}

