#include<bits/stdc++.h>
typedef long long ll;
#define endl "\n"
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;
        
        vector<pair<int, int>> row(n + 1, {0, 0}); 
        vector<pair<int, int>> col(m + 1, {0, 0});

        vector<pair<int, pair<int, int>>> opt(q);

        for (int i = 0; i < q; i++) {
            int op, a, b;
            cin >> op >> a >> b;
            opt[i] = {op, {a, b}};
        }
        
        for (int i = 0; i < q; i++) {
            int op = opt[i].first;
            int x = opt[i].second.first;
            int c = opt[i].second.second;

            if (op == 0) {
                row[x] = {i + 1, c}; 
            } else {
                col[x] = {i + 1, c}; 
            }
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (row[i].first > col[j].first) {
                    cout << row[i].second << " ";
                } else {
                    cout << col[j].second << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}