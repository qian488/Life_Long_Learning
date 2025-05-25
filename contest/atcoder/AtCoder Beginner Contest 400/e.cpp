#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f
#define endl '\n'

void solve(){
    int N = 1000001;
    vector<int> v(N);
    for (int i = 2; i < N; i++) {
        if (v[i] == 0) { 
            for (int j = i; j < N; j += i) {
                v[j]++;
            }
        }
    }
    vector<ll> vec;
    for (ll i = 2; i < N; i++) {
        if (v[i] == 2) {
            vec.push_back(i * i);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        ll a;
        cin >> a;
        cout << *prev(upper_bound(vec.begin(), vec.end(), a)) << endl;
    }
}

int main(){
    int t=1;
    //cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}