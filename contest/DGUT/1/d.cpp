#include<bits/stdc++.h>

using namespace std;

int main(){
    int t = 1;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        /*
        int ans = 0;
        int k = 0;
        while (((n + k) * 7) % m != 0) k++;
        ans = k;
        cout << ans << endl;
        */
       if (m%7==0) m /= 7;
       cout << (m - n % m) % m << endl;
    }
    
    return 0;
}