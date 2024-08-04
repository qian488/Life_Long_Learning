#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl "\n"
#define Awith {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int N = 2e5 + 10;

void Solve(void) {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for(int i = a[n - 1]; i < a[n - 1] + k; i++){
        bool ok = false;
        for(int e : a){
            if(((i - e) / k) % 2) {
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