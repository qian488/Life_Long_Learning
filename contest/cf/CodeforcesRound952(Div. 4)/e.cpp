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
    int k;
    int b[3];
    cin >> b[0] >> b[1] >> b[2] >> k;
    int s[3];
    bool ff = false;
    sort(b, b + 3);
    for (int i = b[0]; i > 0; i--){
        for (int j = b[1]; j > 0;j--){
            for (int t = b[2]; t > 0;t--){
                if (i*j*t==k){
                    s[0] = i;
                    s[1] = j;
                    s[2] = t;
                    ff = true;
                    break;
                }
                }
                if(ff)break;
            }
        if(ff)break;
    }
    sort(s, s + 3);
    if(ff){
        cout << (b[0] - s[0] + 1) * (b[1] - s[1] + 1) * (b[2] - s[2] + 1) << endl;
    }else{
        cout << 0 << endl;
    }
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
