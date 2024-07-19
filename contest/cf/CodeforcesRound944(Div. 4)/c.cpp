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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a>b){
        int t = a;
        a = b;
        b = t;
    }
    set<int> v,k;
    for (int i = a + 1; i <= b - 1; i++){
        v.insert(i);
    }
    for (int i = 1; i <= 12;i++){
        if(i<a||i>b) k.insert(i);
    }
    bool flag = true;
    /*
    for(auto e:v)
        cout << e << " ";
    cout << endl;
    for(auto e:k)
        cout << e << " ";
    */
    if((k.count(c)&&k.count(d))||(v.count(c)&&v.count(d))) flag = false;
    if (!flag){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
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