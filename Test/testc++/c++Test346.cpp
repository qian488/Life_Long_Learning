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
    if (n==2)
    {
        cout << "1 1" << endl;
        cout << "1 2" << endl;
    }else if(n==3){
        cout << "2 1" << endl;
        cout << "2 3" << endl;
        cout << "3 1" << endl;
    }else{
        cout << "1 1" << endl;
        cout << "1 2" << endl;
        cout << "4 2" << endl;
        for (int i = 4; i <= n;i++){
            cout << i << " " << i << endl;
        }
    }
    /*
    cout<<1<<' '<<1<<endl<<1<<' '<<2<<endl;
    for(int i=0;i<n-2;i++) cout<<n-i<<' '<<n-i<<endl;
    */
    
}

int main()
{
    ios 
    int t = 1;
    cin >> t;
    while(t--){
        Solve();
    }
    
    //Codeforces Round 943 (Div. 3)_E	Cells Arrangement
    return 0;
}