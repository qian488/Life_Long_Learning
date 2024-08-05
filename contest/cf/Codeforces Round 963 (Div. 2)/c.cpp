#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl "\n"
#define Awith {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int N = 2e5 + 10;

void Solve(void) {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
/*
    for (ll i = a[n - 1]; i < a[n - 1] + k; i++){
        bool ok = false;
        for(ll e : a){
            if(((i - e) / k) % 2 == 1) {
                ok = true;
                break;
            }
        }
        if(!ok){
            cout << i << endl;
            return;
        }
    }
    cout << "-1" << endl;
*/
    ll v = *max_element(a.begin(), a.end());
    
    for (int i = 0; i < n; i++) {
        if ((v - a[i]) % (2 * k) >= k) {
            v += 2 * k - (v - a[i]) % (2 * k);
        }
    }
    for (int i = 0; i < n; i++) {
        if ((v - a[i]) % (2 * k) >= k) {
            v = -1;
            break;
        }
    }
    cout << v << endl;
}


int main(){
    Awith
    int t = 1;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}