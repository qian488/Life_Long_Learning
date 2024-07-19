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
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    
    s = 'L' + s + 'L';
    n += 2;
    
    bool ok = true;

    int index = 0;
    while(index<n-1){
        if(s[index]=='L'){
            bool flag = false;
            for (int i = index + 1; i < n && i <= index + m;i++){
                if(s[i]=='L'){
                    index = i;
                    flag = true;
                    break;
                }
            }
            if(!flag){
                index += m;
                if(s[index]=='C'){
                    ok = false;
                    break;
                }
            }
        }else{
            index++;
            k--;
            if(s[index]=='C'){
                ok = false;
                break;
            }
        }
    }

    if(ok&&k>=0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
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
