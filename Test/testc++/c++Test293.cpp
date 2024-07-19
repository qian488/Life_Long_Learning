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
const int N=110;
char g[N][N];
void Solve()
{
    int n;
    cin>>n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n;j++){
            cin >> g[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n;j++){
            char c;
            cin >> c;
            if(c!=g[i][j]){
                cout << i + 1 << " " << j + 1 << endl;
                return;
            }
        }
    }
}

int main()
{
    ios 
    
    Solve();
    //AtCoder Beginner Contest 351_B	Spot the Difference
    return 0;
}