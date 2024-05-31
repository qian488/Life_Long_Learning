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
#define MOD 1000000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;

void Solve()
{
    int n;
    cin >> n;
    if(n%2==0){
        int q = n / 2, i = 1;
        while (q--)
        {
            if(q%2==1){ 
                i = 2;
            }else{
                i = 1;
            }
            cout << i << " " << i << " ";
        }
    }else{
        cout << 1 << " ";
        int q = (n - 1) / 2, i = 2;
        while (q--)
        {
            cout << i << " " << i << " ";
            if(q%2==1){ 
                i = 1;
            }else{
                i = 2;
            }
        }
    }
    cout << endl;
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
