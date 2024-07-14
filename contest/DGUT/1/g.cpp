#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, a[701][2], ans = -1;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1];

    for (int i = 1; i < n; i++){
        for (int j = i + 1; j <= n; j++){
            int p = 2, x1 = a[i][0], x2 = a[j][0], y1 = a[i][1], y2 = a[j][1];
            if (x1 == x2 || y1 == y2) continue;
            for (int k = j + 1; k <= n; k++){
                int x3 = a[k][0], y3 = a[k][1];
                if (y3 * (x1 - x2) == x3 * (y1 - y2) + x1 * y2 - x2 * y1) p++;
            }
            if(p>ans) ans = p;
        }
    }
    for (int i = 1; i <= n; i++){
        int p=2;
        for (int j = i + 1; j <= n; j++){
            if (a[i][0] == a[j][0]) p++;
        }
        if(p>ans) ans = p;
    }
    for (int i = 1; i <= n; i++){
        int p=2;
        for (int j = i + 1; j <= n; j++){
            if (a[i][1] == a[j][1]) p++;
        }
        if(p>ans) ans = p;
    }
    cout << ans << endl;
    return 0;
}