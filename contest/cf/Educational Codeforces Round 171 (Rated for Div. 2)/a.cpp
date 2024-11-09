#include <iostream>
using namespace std;
#define endl '\n'

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    int mn = min(x,y);
    if(k<=mn) {
        cout << 0 << " " << 0 << " " << k << " " << 0 << endl;
        cout << 0 << " " << 0 << " " << 0 << " " << k << endl;
    } else {
        cout << 0 << " " << 0 << " " << mn << " " << mn << endl;
        cout << 0 << " " << mn << " " << mn << " " << 0 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
