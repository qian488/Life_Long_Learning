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
//尼玛大小写。。。
void Solve()
{
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    if(n<x||n<y||n<z){
        cout << "No" << endl;
        return;
    }
    if((z<=x&&z>=y)||(z>=x&&z<=y)) cout << "Yes" << endl;
    else cout << "No" << endl;

}

int main()
{
    ios 
    int t = 1;
    //cin >> t;
    while(t--){
        Solve();
    }
    
    //AtCoder Beginner Contest 352_A	AtCoder Line
    return 0;
}