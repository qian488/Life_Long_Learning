#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<stack>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define INF 0x3f3f3f3f
#define MOD 998244353
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;

ll ans = 0;
int arr[1000005];

void Solve(){
    int n = 0;
    cin >> n;
    int temp = 0;
    for(int i = 0;i<n;i++){
        cin >> temp;
        arr[temp]++;
    }
    for(int i = 1;i<=1000000;i++){
        arr[i] += arr[i - 1];
    }
    for(int i = 1;i<=1000000;i++){
        ll num = arr[i] - arr[i - 1];
        if(num){
            ans += (num) * (num - 1) / 2;
            int l = i;
            ans -= num * num;
            while(l<=1000000){
                int r = l + i;
                if(r>1000000+1)r = 1000001;
                ll num2 = arr[r - 1] - arr[l - 1];
                ans += num2 * (l / i) * num;
                l += i;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    ios 
    int t = 1;
    //cin >> t;
    while(t--){
        Solve();
    }
    
    return 0;
}
