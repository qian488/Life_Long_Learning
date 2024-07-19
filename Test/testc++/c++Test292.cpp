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
const int N=1e6+10;
#define P 20240401


void Solve()
{
    int a[9], b[8];
    int suma = 0, sumb = 0;
    for (int i = 0; i < 9;i++){ 
        cin >> a[i];
        suma += a[i];
    }
    for (int i = 0; i < 8;i++){
        cin >> b[i];
        sumb += b[i];
    }
    cout << suma - sumb + 1 << endl;
}

int main()
{
    ios 
    int t = 1;
    while(t--){
        Solve();
    }
    
    //AtCoder Beginner Contest 351_A	The bottom of the ninth
    return 0;
}