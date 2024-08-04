#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl "\n"
#define Awith {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int N = 2e5 + 10;

void Solve(void){
    int n;
    cin >> n; 
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    /*
    int cnt = 0;
    for(int i:a) cnt += i % 2 == 0;
    if(cnt == n) {
        cout << 0 << endl;
        return;
    }
    int ans = cnt;
    int sum = 0;
    for(int i = n - 1; i >= 0; i--){
        if(a[i] % 2){
            sum = a[i];
            break;
        }
    }

    for (int i = 0; i < n;i++){
        if(a[i] % 2) {
            i++;
            continue;
        }
        if(a[i] < sum) sum += a[i];
        else{
            cnt++;
            sum += 2 * a[i];
        }
    }
    if(ans != cnt) ans++;
    cout << ans << endl;
    */
    vector<int> v;
    int maxn = 0;
    for (int i = 0; i < n;i++){
        if(a[i]%2==0){
            v.push_back(a[i]);
        }else{
            maxn = max(maxn, a[i]);
        }
    }
    if(v.size()==n||v.size()==0){
        cout << 0 << endl;
    }else{
        bool ok = true;
        for(auto e:v){
            if(maxn<e){
                ok = false;
                break;
            }else{
                maxn += e;
            }
        }
        if(ok){
            cout << v.size() << endl;
        }else{
            cout << v.size() + 1 << endl;
        }
    }
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