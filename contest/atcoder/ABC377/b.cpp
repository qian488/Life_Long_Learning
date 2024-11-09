#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s[8];
    for(int i = 0; i < 8; i++) cin >> s[i];
    
    vector<bool> row(8, false), col(8, false);

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(s[i][j] == '#') {
                row[i] = true;
                col[j] = true;
            }
        }
    }
    
    int ans = 0;

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(!row[i] && !col[j]) {
                ans++;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}
