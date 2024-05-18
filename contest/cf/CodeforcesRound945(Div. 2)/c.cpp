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
#define MOD 100000000
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;

void Solve()
{
    int n;
    cin >> n;
    vector<int> v(n), ans(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> p, q;
    for (int i = 1; i+1 < n; i++){
        if (i%2==1){
            p.push_back(i);
        }else{
            q.push_back(i);
        }
    }

    cout << "================================" << endl;
    for(auto e:p)
        cout << e << " ";
    cout << endl;
    for(auto e:q)
        cout << e << " ";
    cout << endl;

    for (int e:p){
        if (v[e]==1){
            swap(p, q);
            break;
        }
    }

    cout << "================================" << endl;
    for(auto e:p)
        cout << e << " ";
    cout << endl;
    for(auto e:q)
        cout << e << " ";
    cout << endl;

    q.push_back(0);
    q.push_back(n - 1);
    sort(p.begin(), p.end(), [&](int a, int b)
         { return v[a] < v[b]; });
    sort(q.begin(), q.end(), [&](int a, int b)
         { return v[a] > v[b]; });
    
    cout << "================================" << endl;
    for(auto e:p)
        cout << e << " ";
    cout << endl;
    for(auto e:q)
        cout << e << " ";
    cout << endl;
    
    int l = 1,r = n;
    for (int e:p) ans[e] = r--;
    for (int e:q) ans[e] = l++;

    for (int e:ans) cout << e << " ";
    cout<< endl;
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
