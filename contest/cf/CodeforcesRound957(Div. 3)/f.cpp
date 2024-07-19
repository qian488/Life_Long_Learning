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
#include<bitset>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;

void Solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    int ans = 1;
    int index = 0;
    set<int> st;
    st.insert(x);
    while (index!=n){
        if(x%a[index]==0){
            for (auto e:st){
                int pos = e;
                if(pos%a[index]==0){ 
                    pos /= a[index];
                }
                st.insert(pos);
                if(pos==1){
                    st.clear();
                    st.insert(x);
                    st.insert(x / a[index]);
                    ans++;
                    break;
                }
            }
        }
        index++;
    }
    cout << ans << endl;
}

int main()
{
    ios 
    int t = 1;
    cin >> t;
    while(t--){
        Solve();
    }
    
    return 0;
}
