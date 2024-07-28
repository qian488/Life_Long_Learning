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
#define INF (ll)2e18
#define MOD 100000007
#define endl "\n"
#define ios {ios::sync_with_stdio(0);cin.tie(0);}
const int N=2e5+10;

void Solve()
{
    int n;
    cin >> n;

    if(n==1){
        cout << "1\n1\n";
    }
    else if(n==2){
        cout << "2\n1 2\n";
    }
    else if(n==3){
        cout << "2\n1 2 2\n";
    }
    else if(n==4){
        cout << "3\n1 2 2 3\n";
    }
    else if(n==5){
        cout << "3\n1 2 2 3 3\n";
    }
    else{
        cout<<4<<endl;
        for(int i=1;i<=n;i++)
            cout << i % 4 + 1 << " ";
        cout<<endl;
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
