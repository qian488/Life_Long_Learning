#include<bits/stdc++.h>
typedef long long ll;
#define endl "\n"
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> v(n), w(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i] >> w[i];
    }
    
    vector<int> dp(m + 1, 0);
    
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= v[i]; j--) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    
    cout << *max_element(dp.begin(), dp.end()) << endl;

    return 0;
}