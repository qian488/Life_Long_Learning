#include <iostream>
#include <string>
using namespace std;

#define endl "\n"
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7;
const int N=2e5+5;

void solve(){
    int n;
    cin >> n;
    
    if (n == 1 || n == 3) {
        cout << "-1" << endl;
        return;
    }
    
    string ans;
    if (n % 2 == 0) {
        ans = string(n - 2, '3') + "66";
    } else {
        ans = string(n - 4, '3') +"6366";
    }
    
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
